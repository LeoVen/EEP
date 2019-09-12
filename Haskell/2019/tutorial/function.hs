
{-
 common notation is to use a ' at the end for a function that isn't lazy or
 that it is a slightly modified version
-}

-- integer division
-- version 1
idiv x y = floor (x / y)

-- version 2
idiv' x y = round (x / y)




var1 = idiv 10 6

var2 = idiv' 10 6
