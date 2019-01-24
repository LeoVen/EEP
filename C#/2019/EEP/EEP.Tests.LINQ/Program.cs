using EEP.Tests.LINQ.Extensions;
using EEP.Tests.LINQ.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Globalization;
using System.Threading;
using EEP.Tests.LINQ.Programs;

// Available commands in query syntax
// Where,
// Select,
// SelectMany,
// Join,
// GroupJoin,
// OrderBy,
// OrderByDescending,
// ThenBy,
// ThenByDescending,
// GroupBy,
// Cast

namespace EEP.Tests.LINQ
{
    class Program
    {
        static void Main(string[] args)
        {
            var enUS = new CultureInfo("en-US");

            Thread.CurrentThread.CurrentCulture = enUS;

            string path = @"C:\windows";

            ShowLargeFilesWithLinq(path);

            IEnumerable<Employee> list = new List<Employee>()
            {
                new Employee { Id = 1, Name = "Alex" },
                new Employee { Id = 2, Name = "Rosalind" },
                new Employee { Id = 3, Name = "Scott" }
            };

            // Hardcoded foreach
            IEnumerator<Employee> enumerator = list.GetEnumerator();
            while (enumerator.MoveNext())
            {
                Console.WriteLine(enumerator.Current);
            }

            Console.WriteLine(list.MyCount(1));
            Console.WriteLine(list.Count());

            string d = "10.0";
            double dParsed = d.ToDouble();

            // Last parameter is the return, all the rest are parameter types
            Func<Employee, bool> f = StartsWithLetter;
            Func<double, double> root = (double x) => Math.Sqrt(x);
            Func<double, double, double> square = (x, y) => x * y;
            Func<double, double> cube = (double X) => Math.Pow(X, 3.0);

            Action<double> write = x => Console.WriteLine(x);

            write(cube(root(square(7.0, 6.0))));
            
            // Named Method
            var filter1 = list.Where(StartsWithLetter);

            // Anonymous Method
            var filter2 = list.Where(delegate (Employee arg)
            {
                return arg.Name.StartsWith("A");
            });

            // Lambda
            var filter3 = list.Where(E => E.Name.StartsWith("A"));

            foreach (var employee in list.Where(E => E.Name.StartsWith("A")))
            {
                Console.WriteLine(employee);
            }

            var randomNumbers = CustomExtensions.Random().Where(n => n > 0.5).Take(100);

            foreach (var r in randomNumbers)
            {
                Console.Write($"{r} ");
            }

            Console.WriteLine();

            CarDatasetProgram.MainProgram();

            ManufacturersDatasetProgram.MainProgram();

            Console.ReadKey();
        }

        private static bool StartsWithLetter(Employee arg)
        {
            return arg.Name.StartsWith("A");
        }

        private static void ShowLargeFilesWithLinq(string path)
        {
            var files = new DirectoryInfo(path).GetFiles();

            var query = new DirectoryInfo(path).GetFiles()
                .OrderByDescending(f => f.Length)
                .Take(10)
                .ToList(); // Forces iteration

            // Query syntax
            // Starts with from
            // Ends with select or group    
            var q = from f in files
                    where f.Name.Length < 20.0 && f.Length > 10000.0
                    orderby f.Length ascending
                    select f;
    
            // This will only be executed when q's elements are yielded
            q.Take(10);
            
            foreach (var file in query)
            {
                Console.WriteLine($"{file.Name, -20} : {file.Length, 10:N0}");
            }

            Console.WriteLine("\nQuery Completed\n---------------\n\n");

            foreach (var file in q)
            {
                Console.WriteLine($"{file.Name,-20} : {file.Length,10:N0}");
            }

            Console.WriteLine("\nQuery Completed\n---------------\n\n");
        }
    }
}
