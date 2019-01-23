using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.Tests.Training
{
    public class GradeBook
    {
        public NameChangedDelegate NameChanged;

        private List<Grade> gradeList;

        private string _name;

        public string Name
        {
            get
            {
                return _name;
            }
            set
            {
                if (!String.IsNullOrEmpty(value))
                {
                    if (_name != value && NameChanged != null)
                    {
                        // invoke delegate NameChanged(_name, value)
                        NameChanged(this, new NameChangedEventArgs(_name, value));
                    }

                    _name = value;
                }
            }
        }

        public GradeBook()
        {
            gradeList = new List<Grade>();

            Name = "";
        }

        public void AddGrade(Grade G)
        {
            gradeList.Add(G);
        }

        public List<Grade> GetList()
        {
            return new List<Grade>(gradeList);
        }

        public Grade GetGrade(int index)
        {
            return gradeList[index];
        }

        public override string ToString()
        {
            StringBuilder strb = new StringBuilder(8 * gradeList.Count);

            strb.Append("\nMy Grades\n[ ");
            foreach (var grade in gradeList)
            {
                strb.AppendFormat("{0}{1}", grade.ToString(), grade == gradeList.Last<Grade>() ? "" : ", ");
            }
            strb.Append(" ]");

            return strb.ToString();
        }
    }
}
