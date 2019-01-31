using System;
using System.Collections;

namespace DataStructures.Library
{
    public class BitArray
    {
        #region Private Properties

        // The array of bits
        private UInt64[] Bits;

        // How many bits there are in a single word
        private static readonly int _WordSize = 64;

        // For 64 bit words
        private static readonly int _BitShifts = 6;

        // Default size when instantiating a new BitArray
        private static readonly int _DefaultSize = 1;

        #endregion

        #region Public Properties

        // Total number of words (effective size of Bits array)
        public int CountWords { get; private set; }

        public int CountBits { get => CountWords * _WordSize; }

        #endregion

        #region Constructors

        public BitArray()
        {
            Bits = new ulong[_DefaultSize];
            
            CountWords = _DefaultSize;
        }

        public BitArray(int requiredBits, bool defaultValue)
        {
            if (requiredBits <= 0)
                throw new ArgumentOutOfRangeException($"The minimum amount of {nameof(requiredBits)} is 1");

            int totalWords = BitToWordIndex(requiredBits - 1) + 1;

            Bits = new ulong[totalWords];

            ulong value = defaultValue ? 1ul : 0ul;

            for (var i = 0; i < Bits.Length; i++)
                Bits[i] = value;

            CountWords = totalWords;
        }

        #endregion

        #region Helper Functions

        private int BitToWordIndex(int bitIndex)
        {
            return bitIndex >> _BitShifts;
        }

        #endregion
    }
}
