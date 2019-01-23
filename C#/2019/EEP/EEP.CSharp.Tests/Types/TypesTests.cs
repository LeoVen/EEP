using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using EEP.Tests.Training;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EEP.CSharp.Tests.Types
{
    [TestClass]
    public class TypesTests
    {
        [TestMethod]
        public void ReferenceTypes()
        {
            List<int> l1 = new List<int>();
            List<int> l2 = l1;

            Assert.AreEqual(l1, l2);
        }

        [TestMethod]
        public void ValueTypes()
        {
            int a = 20;
            int b = a;

            a = 10;

            Assert.AreEqual(20, b);
        }

        [TestMethod]
        public void StringType()
        {
            string name1 = "Lord";
            string name2 = "lord";

            bool result = String.Equals(name1, name2, StringComparison.InvariantCultureIgnoreCase);

            Assert.IsTrue(result);
        }

        [TestMethod]
        public void ReferenceTypePassByValue()
        {
            GradeBook g1 = new GradeBook();

            GradeBook g2 = g1;

            ChangeName(g2);
            Assert.AreEqual("A Gradebook", g1.Name);
        }

        private void ChangeName(GradeBook book)
        {
            book.Name = "A Gradebook";
        }

        [TestMethod]
        public void ValueTypePassByValue()
        {
            int x = 46;

            IncrementNumber(x);

            Assert.AreEqual(46, x);
        }

        private void IncrementNumber(int n)
        {
            n += 1;
        }

        [TestMethod]
        public void ReferenceTypePassByReference()
        {
            GradeBook g1 = new GradeBook();

            GradeBook g2 = g1;

            ChangeNameByReference(ref g2);

            Assert.AreNotEqual(g2, g1);
        }

        private void ChangeNameByReference(ref GradeBook book)
        {
            book = new GradeBook();

            book.Name = "A Gradebook";
        }

        [TestMethod]
        public void ValueTypePassByReference()
        {
            int x = 46;

            IncrementNumberByReference(ref x);

            Assert.AreEqual(47, x);
        }

        private void IncrementNumberByReference(ref int n)
        {
            n += 1;
        }

        [TestMethod]
        public void OutputValue()
        {
            int[] myList;

            MakeList(out myList);

            Assert.AreEqual(10, myList.Length);
        }

        private void MakeList(out int[] list)
        {
            list = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        }

        [TestMethod]
        public void AddDaysToDateTime()
        {
            DateTime date = new DateTime(2015, 1, 1);

            date = date.AddDays(1);

            Assert.AreEqual(2, date.Day);
        }

        [TestMethod]
        public void AddStringToString()
        {
            string s = "Hello  ";

            s = s.TrimEnd();

            Assert.AreEqual("Hello", s);
        }

        [TestMethod]
        public void ArrayType()
        {
            double[] grades;

            AddGrades(out grades);

            Assert.AreEqual(20.0, grades.Sum(), 0.000001);
        }

        public void AddGrades(out double[] grades)
        {
            grades = new double[4] { 8.0, 2.0, 3.0, 7.0 };
        }

        [TestMethod]
        public void ArrayTypePosition()
        {
            double[] grades = new double[5];

            ChangeASingleGrade(grades);

            Assert.AreEqual(10.0, grades[0], 0.000001);
        }

        public void ChangeASingleGrade(double[] grades)
        {
            grades[0] = 10.0;
        }
    }
}
