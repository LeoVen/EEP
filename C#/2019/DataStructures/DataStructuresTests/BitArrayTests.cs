using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using DataStructures.Library;

namespace DataStructures.Tests
{
    [TestClass]
    public class BitArrayTests
    {
        [TestMethod]
        public void BitArrayRequiredBits()
        {
            BitArray bits = new BitArray(640, true);
            
            Assert.AreEqual(640, bits.CountBits);
        }

        [TestMethod]
        public void BitArrayCountExact()
        {
            BitArray bits = new BitArray(256, false);

            Assert.AreEqual(4, bits.CountWords);
        }

        [TestMethod]
        public void BitArrayCountMoreOne()
        {
            BitArray bits = new BitArray(257, false);

            Assert.AreEqual(5, bits.CountWords);
        }

        [TestMethod]
        public void BitArrayCountLessOne()
        {
            BitArray bits = new BitArray(255, false);

            Assert.AreEqual(4, bits.CountWords);
        }
    }
}
