
factors n = [x | x <- [1..n], mod n x == 0]

prime n = factors n == [1, n]

primes = filter prime [1..]


sievePrimes = sieve [2..]

sieve (p:ps) = p : sieve [x | x <- ps, mod x p /= 0]


twin (x, y) = y == x + 2

twins = filter twin (zip primes (tail primes))

sieveTwins = filter twin (zip sievePrimes (tail sievePrimes))

