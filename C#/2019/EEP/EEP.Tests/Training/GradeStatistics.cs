using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.Training
{
    public class GradeStatistics
    {
        private GradeBook _book;

        private bool _computed;
        private double _maximum, _minimum, _average;

        public double Maximum
        {
            get
            {
                if (!_computed)
                    throw new InvalidOperationException("Statistics have not been computed");

                return _maximum;
            }
            private set
            {
                _maximum = value;
            }
        }

        public double Minimum
        {
            get
            {
                if (!_computed)
                    throw new InvalidOperationException("Statistics have not been computed");

                return _minimum;
            }
            private set
            {
                _minimum = value;
            }
        }

        public double Average
        {
            get
            {
                if (!_computed)
                    throw new InvalidOperationException("Statistics have not been computed");

                return _average;
            }
            private set
            {
                _average = value;
            }
        }

        public GradeStatistics(GradeBook book)
        {
            _book = book;

            Maximum = 0;
            Minimum = 0;
            Average = 0;

            _computed = false;
        }

        public void Compute()
        {
            var gradeList = _book.GetList();

            Maximum = MaxGrade(gradeList);

            Minimum = MinGrade(gradeList);

            Average = AvgGrade(gradeList);

            _computed = true;
        }

        private double MaxGrade(List<Grade> gradeList)
        {
            if (gradeList.Count == 0)
                return 0;

            double max = gradeList[0].ToArray().Max();

            foreach (var grade in gradeList)
            {
                double currentMax = grade.ToArray().Max();

                if (currentMax > max)
                    max = currentMax;
            }

            return max;
        }

        public double MinGrade(List<Grade> gradeList)
        {
            if (gradeList.Count == 0)
                return 0;

            double min = gradeList[0].ToArray().Min();

            foreach (var grade in gradeList)
            {
                double currentMin = grade.ToArray().Min();

                if (currentMin < min)
                    min = currentMin;
            }

            return min;
        }

        private double AvgGrade(List<Grade> gradeList)
        {
            double sum = 0.0;
            int total = 0;

            foreach (var grade in gradeList)
            {
                sum += grade.ToArray().Sum();
                total += grade.Length;
            }

            return sum / total;
        }
    }
}
