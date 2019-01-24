using EEP.Tests.LINQ.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.LINQ.Programs
{
    public static class ManufacturersDatasetProgram
    {
        public static void MainProgram()
        {
            Console.WriteLine("\n");

            var cars = CarDatasetProgram.ProcessCars("Data/fuel.csv");
            var manufacturers = ProcessManufacturers("Data/manufacturers.csv");

            // Joining
            var query = cars
                .Join(
                    manufacturers,
                    c => c.Manufacturer,
                    m => m.Name,
                    (c, m) => new
                    {
                        m.Headquarters,
                        c.Name,
                        c.Combined
                    })
                .OrderByDescending(c => c.Combined)
                .ThenBy(c => c.Name);

            var querySyntax =
                from car in cars
                join manufacturer in manufacturers
                    on car.Manufacturer equals manufacturer.Name
                orderby car.Combined descending, car.Name ascending
                select new
                {
                    manufacturer.Headquarters,
                    car.Name,
                    car.Combined
                };

            var craze = cars
                .Join(
                    manufacturers,
                    c => c.Manufacturer,
                    m => m.Name,
                    (c, m) => new
                    {
                        Car = c,
                        Manufacturer = m
                    })
                .OrderByDescending(c => c.Car.Combined)
                .ThenBy(c => c.Car.Name)
                .Select(o => new
                {
                    o.Manufacturer.Headquarters,
                    o.Car.Name,
                    o.Car.Combined
                });

            var queryCrazeSyntax =
                from car in cars
                join manufacturer in manufacturers
                    on new { car.Manufacturer, car.Year }
                        equals
                       new { Manufacturer = manufacturer.Name, manufacturer.Year }
                orderby car.Combined descending, car.Name ascending
                select new
                {
                    manufacturer.Headquarters,
                    car.Name,
                    car.Combined
                };

            var queryCraze = cars
                .Join(
                    manufacturers,
                    c => new { c.Manufacturer, c.Year },
                    m => new { Manufacturer = m.Name, m.Year },
                    (c, m) => new
                    {
                        m.Headquarters,
                        c.Name,
                        c.Combined
                    })
                .OrderByDescending(c => c.Combined)
                .ThenBy(c => c.Name);

            foreach (var car in query.Take(10))
            {
                Console.WriteLine($"{car.Headquarters}, {car.Name}, {car.Combined}");
            }

            Console.WriteLine("\n\nGROUPING\n");

            // Grouping
            var queryGroupSyntax =
                from car in cars
                group car by car.Manufacturer.ToUpper() into manufacturer
                orderby manufacturer.Key
                select manufacturer;

            var queryGroup = cars
                .GroupBy(c => c.Manufacturer.ToUpper())
                .OrderBy(g => g.Key);

            foreach (var group in queryGroup)
            {
                Console.WriteLine($"{group.Key} has {group.Count()} cars");
            }

            Console.WriteLine("\n");

            foreach (var group in queryGroupSyntax)
            {
                Console.WriteLine($"{group.Key}");
                foreach (var car in group.OrderByDescending(c => c.Combined).Take(2))
                {
                    Console.WriteLine($"\t{car.Name} : {car.Combined}");
                }
            }

            // GroupJoin
            var queryGroupJoinSyntax =
                from manufacturer in manufacturers
                join car in cars
                    on manufacturer.Name equals car.Manufacturer
                    into carGroup
                orderby manufacturer.Name
                select new
                {
                    Manufacturer = manufacturer,
                    Cars = carGroup
                };

            var queryGroupJoin = manufacturers
                .GroupJoin(
                    cars,
                    m => m.Name,
                    c => c.Manufacturer,
                    (m, g) =>
                        new
                        {
                            Manufacturer = m,
                            Cars = g
                        })
                .OrderBy(m => m.Manufacturer.Name);
            Console.WriteLine("\n");

            foreach (var group in queryGroupJoin)
            {
                Console.WriteLine($"{group.Manufacturer.Name}:{group.Manufacturer.Headquarters}");
                foreach (var car in group.Cars.OrderByDescending(c => c.Combined).Take(2))
                {
                    Console.WriteLine($"\t{car.Name} : {car.Combined}");
                }
            }

            // Grou by country
            var queryGroupCountrySyntax =
                from manufacturer in manufacturers
                join car in cars
                    on manufacturer.Name equals car.Manufacturer
                    into carGroup
                select new
                {
                    Manufacturer = manufacturer,
                    Cars = carGroup
                } into result
                group result by result.Manufacturer.Headquarters;

            var queryGroupCountry = manufacturers
                .GroupJoin(
                    cars,
                    m => m.Name,
                    c => c.Manufacturer,
                    (m, g) =>
                        new
                        {
                            Manufacturer = m,
                            Cars = g
                        })
                .GroupBy(m => m.Manufacturer.Headquarters);

            Console.WriteLine("\n");

            foreach (var group in queryGroupCountry)
            {
                Console.WriteLine($"{group.Key}");
                foreach (var car in group.SelectMany(g => g.Cars)
                                         .OrderByDescending(c => c.Combined)
                                         .Take(3))
                {
                    Console.WriteLine($"\t{car.Name} : {car.Combined}");
                }
            }

            // Aggregation
            var queryAggregationSyntax =
                from car in cars
                group car by car.Manufacturer
                    into carGroup
                select new
                {
                    Name = carGroup.Key,
                    Max = carGroup.Max(c => c.Combined),
                    Min = carGroup.Min(c => c.Combined),
                    Avg = carGroup.Average(c => c.Combined)
                };

            var queryAggregationType =
                from car in cars
                group car by car.Manufacturer
                    into carGroup
                select new
                {
                    Name = carGroup.Key,
                    Max = carGroup.Max(c => c.Combined),
                    Min = carGroup.Min(c => c.Combined),
                    Avg = carGroup.Average(c => c.Combined)
                } into result
                orderby result.Max descending /* can be result.Max, result.Min, result.Avg */
                select result;

            Console.WriteLine("\n\n\n");

            foreach (var result in queryAggregationType)
            {
                Console.WriteLine($"{result.Name}");
                Console.WriteLine($"\tMax: {result.Max.ToString("N2")}");
                Console.WriteLine($"\tMin: {result.Min.ToString("N2")}");
                Console.WriteLine($"\tAvg: {result.Avg.ToString("N2")}");
            }

            // More efficient aggregation
            var queryAggregationExternal = cars
                .GroupBy(c => c.Manufacturer)
                .Select(g =>
                {
                    var result = g.Aggregate(new CarStatistics(),
                                            (acc, car) => acc.Accumulate(car),
                                            acc => acc.Compute());

                    return new
                    {
                        Name = g.Key,
                        Avg = result.Avg,
                        Min = result.Min,
                        Max = result.Max
                    };
                })
                .OrderBy(r => r.Max);

            Console.WriteLine("\n\n\n");

            foreach (var result in queryAggregationType)
            {
                Console.WriteLine($"{result.Name}");
                Console.WriteLine($"\tMax: {result.Max.ToString("N2")}");
                Console.WriteLine($"\tMin: {result.Min.ToString("N2")}");
                Console.WriteLine($"\tAvg: {result.Avg.ToString("N2")}");
            }
        }

        private static List<Manufacturer> ProcessManufacturers(string path)
        {
            return File.ReadAllLines(path)
                .Skip(1)
                .Where(line => line.Length > 1)
                .Select(l =>
                {
                    var columns = l.Split(',');

                    return new Manufacturer
                    {
                        Name = columns[0],
                        Headquarters = columns[1],
                        Year = int.Parse(columns[2])
                    };
                })
                .ToList();
        }
    }
}
