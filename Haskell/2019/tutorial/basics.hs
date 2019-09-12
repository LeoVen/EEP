-- One line comment

{-
    Multi-line comments can
    be written like this
-}

-- modules
import Data.List
import System.IO

-- Bounded class
maxInt = maxBound :: Int
minInt = minBound :: Int

-- Integer - unbounded

-- Float
-- Double

-- Bool True False

-- Char ''

-- Tuple

-- Declare variable as always the same type
alwaysInt :: Int
alwaysInt = 5

-- Functions

-- sum function
sumOfNums = sum [1..1000]

-- Prefix operator
modEx0 = mod 5 4
-- Infix operator
modEx1 = 5 `mod` 4


negNumSum = 5 + (-4)

num7 = 7 :: Int

sqrtOf7 = sqrt (fromIntegral num7)
