using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.Training
{
    public class Grade
    {
        private double[] _grades;

        public int Length;

        public Grade(params double[] grades)
        {
            _grades = new double[grades.Length];

            for (var i = 0; i < grades.Length; i++)
            {
                _grades[i] = grades[i];
            }

            Length = _grades.Length;
        }

        public double this[int index]
        {
            get
            {
                if (index < 0 || index >= _grades.Length)
                    throw new IndexOutOfRangeException(nameof(index));

                return _grades[index];
            }
            set
            {
                if (index < 0 || index >= _grades.Length)
                    throw new IndexOutOfRangeException(nameof(index));

                _grades[index] = value;
            }
        }

        public override string ToString()
        {
            return new StringBuilder().AppendFormat("[ {0} ]", string.Join(", ", _grades)).ToString();
        }

        public double[] ToArray()
        {
            return _grades.ToArray();
        }
    }
}
