using EEP.Tests.LINQ.Extensions;
using EEP.Tests.LINQ.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.LINQ.Programs
{
    public class CarDatasetProgram
    {
        public static void MainProgram()
        {
            // Loading car fuel consumption data set

            Console.WriteLine("\n");

            var cars = ProcessCars("Data/fuel.csv");

            var query = cars
                .Where(c => c.Manufacturer == "BMW" && c.Year == 2016)
                .OrderByDescending(c => c.Combined)
                .ThenBy(c => c.Name)
                .Select(c => c);

            var querySyntax =
                from car in cars
                where car.Manufacturer == "BMW" && car.Year == 2016
                orderby car.Combined descending, car.Name ascending
                select car;

            var topCarQuerySyntax = (
                from car in cars
                where car.Manufacturer == "BMW" && car.Year == 2016
                orderby car.Combined descending, car.Name ascending
                select car
                ).LastOrDefault(); // Might return null

            var topCar = cars
                .OrderByDescending(c => c.Combined)
                .ThenBy(c => c.Name)
                .Select(c => c)
                .First(c => c.Manufacturer == "BMW" && c.Year == 2016);

            var craze = cars
                .Where(c => c.Manufacturer == "BMW" && c.Year == 2016)
                .OrderByDescending(c => c.Combined)
                .ThenBy(c => c.Name)
                .Select(c => new
                {
                    c.Manufacturer, c.Name, c.Combined
                });

            var ford = cars.Any(c => c.Manufacturer == "Ford");
            var allFord = cars.All(c => c.Manufacturer == "Ford");

            foreach (var car in query.Take(10))
            {
                Console.WriteLine(car);
            }

            Console.WriteLine();

            foreach (var an in craze.Take(10))
            {
                Console.WriteLine($"{an.Manufacturer}, {an.Name}, {an.Combined}");
            }

            Console.WriteLine("\nTop Car:");
            Console.WriteLine(topCarQuerySyntax);

            Console.Write("Is there a car manufactured by Ford? ");
            Console.WriteLine(ford);

            Console.Write("Are all manufactured cars by Ford? ");
            Console.WriteLine(allFord);

            // Anonymous type
            var anon = new
            {
                Name = "Scott"
            };

            var crumb = new
            {
                Model = "BWM",
                Cylinders = 4
            };

            Console.WriteLine("\n\nSelectMany example");

            // Equivalent
            var selecting = cars.Select(c => c.Name);
            foreach (var name in selecting.Take(10))
            {
                Console.WriteLine(name);
            }

            // SelectMany
            foreach (var name in selecting.Take(10))
            {
                foreach (var character in name)
                {
                    Console.WriteLine(character);
                }
            }

            // Short path
            var selectManyExample = cars.SelectMany(c => c.Name);
            // Now a single foreach would pass through all characters

            // Most popular letter in car names

        }

        internal static List<Car> ProcessCars(string path)
        {
            return File.ReadAllLines(path)
                .Skip(1)
                .Where(line => line.Length > 1)
                .ToCar()
                .ToList();
        }
    }
}
