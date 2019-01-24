using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.LINQ.Models
{
    public class Car
    {
        public int Year { get; set; }
        public string Manufacturer { get; set; }
        public string Name { get; set; }
        public double Displacement { get; set; }
        public int Cylinders { get; set; }
        public int City { get; set; }
        public int Highway { get; set; }
        public int Combined { get; set; }
        
        public override string ToString()
        {
            return $"Year: {Year}, Manufacturer: {Manufacturer}, Name: {Name}, Displacement: {Displacement}, Cylinders: {Cylinders}, City: {City}, Highway: {Highway}, Combined: {Combined}";
        }
    }

    public class CarStatistics
    {
        public int Max { get; set; }
        public int Min { get; set; }
        public int Total { get; set; }
        public int Count { get; set; }
        public int Avg { get; set; }

        public CarStatistics()
        {
            Max = Int32.MinValue;
            Min = Int32.MaxValue;
        }

        public CarStatistics Accumulate(Car car)
        {
            Total += car.Combined;
            Count += 1;

            Max = Math.Max(Max, car.Combined);
            Min = Math.Min(Min, car.Combined);

            return this;
        }

        public CarStatistics Compute()
        {
            Avg = Total / Count;

            return this;
        }
    }
}
