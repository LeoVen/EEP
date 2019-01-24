using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.LINQ.Extensions
{
    public static class CustomExtensions
    {
       static public double ToDouble(this string data)
        {
            return double.Parse(data);
        }

        static public int MyCount<T>(this IEnumerable<T> sequence, int param)
        {
            Console.WriteLine($"You passed the param {param}");

            int count = 0;

            foreach (var item in sequence)
            {
                count++;
            }

            return count;
        }

        static public IEnumerable<T> MyFilter0<T>(this IEnumerable<T> source, Func<T, bool> predicate)
        {
            foreach (var item in source)
            {
                if (predicate(item))
                {
                    // See also: yield break;
                    yield return item;
                }
            }
        }

        static public IEnumerable<double> Random()
        {
            var random = new Random();

            while (true)
            {
                yield return random.NextDouble();
            }
        }
    }
}
