/**
 * @file EEP.App0.Util.Primes.java
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/02/2019
 *
 * First Java Class: Utility Class
 *
 */
package EEP.App0.Util;

/**
 * A class that helps dealing with prime numbers.
 * 
 */
public class Primes {

    /**
     * Makes a primality test against the number {@code n}.
     * 
     * @param n the number to be checked if it is prime
     * 
     * @return true if {@code n} is prime
     */
    public static boolean isPrime(long n)
    {
        if (n <= 1)
                return false;
        if (n <= 3)
                return true;

        if (n % 2 == 0 || n % 3 == 0)
                return false;

        for (long i = 5; i * i <= n; i += 6)
                if (n % i == 0 || n % (i + 2) == 0)
                        return false;

        return true;
    }
}
