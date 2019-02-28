/**
 * @file EEP.App0.Main.java
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 27/02/2019
 *
 * First Java Class
 *
 */
package EEP.App0;

import EEP.App0.Util.Constants;
import EEP.App0.Util.Primes;
import java.util.Scanner;

/**
 * The main class of my package.
 * 
 */
public class Main {

    /**
     * The start of my program
     * 
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        System.out.println("I currently have three constants:");
        System.out.printf("| pi: %f | e  : %f | k  : %f |\n", Constants.PI,
                Constants.E, Constants.K);
        
        boolean correct = false;
        
        System.out.println("Primality tester.");
        System.out.println("Please type in a number between 1 and"
                + " 9223372036854775807.");
        System.out.println("Type in a negative number or 0 (zero) to exit.");
        
        while (!correct)
        {
            try {
                System.out.print(" > ");
                Scanner reader = new Scanner(System.in);
                long i = reader.nextLong();
                
                if (i <= 0)
                    break;

                if (Primes.isPrime(i)) {
                    System.out.println("Your number is prime!");
                }
                else {
                    System.out.println("Your number is not prime!");
                }
                
            } catch (Exception e) {
                System.out.println("Please write a valid integer"
                        + " or a number less than 1 to exit");
            }
        }
    }
}
