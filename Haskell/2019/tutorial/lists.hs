import Data.List

var = "Hello World!"

-- Takes two lists
concatenation = "Hello " ++ "World!"

-- Takes an element and a list
consOperator = 'A' : "pple"

-- Indexes start at 0

accessByIndex = var !! 6

-- Takes a list and returns its first element
firstElement = head var

-- Takes a list and returns its last element
lastElement = last var

-- Takes a list, removes its first element and returns the new list
allButFirst = tail var

-- Takes a list, removes its last element and returns the new list
allButLast = init var

-- Lists within lists can't be of different types
listOfLists = [[1,2,3,4],[5,3,3,3],[1,2,2,3,4],[1,2,3]]

lengthOfList = length listOfLists

-- Check if a list is empty
isEmpty = null var

reversed = reverse var

-- Takes as many elements from the beginning of the list
immaTakeThis = take 3 var
immaTakeItAll = take 10000 var
emptyList = take 0 var

-- Drops the first elements from the beginning of the list
dropIt = drop 3 var
dropItAll = drop 10000 var

iList = [0, 1, 2, 3, 4, 5]

minVal = minimum iList
maxVal = maximum iList

listSum = sum iList
listProd = product iList

-- Takes an element and says if it is present in the list
isOnTheList4 = elem 4 iList
isOnTheList9 = 9 `elem` iList

myRange = [1..20]

-- Step between 3 and 6 up to 20
myRangeWithStep = [3, 6..20]
myFloatingRange = [0.1, 0.2..1]

-- Cycle will create an infinite cycle from a list
dontDisplayThisList = cycle [1, 2, 3]

-- Repeat will repeat the same element
dontDisplayThisElement = repeat 5

-- Replicate will replicate a value n times
tenOfTens = replicate 10 10


-- List comprehension
-- [output | inputSet, predicate]
firstSquares = [x * x | x <- [1..10]]

firstOddSquares = [x * x | x <- [1..10], x `mod` 2 /= 0]

removeLowerCase [Char] str = [s | s <- str, s `elem` ['A'..'Z']]

rlc = removeLowerCase var
