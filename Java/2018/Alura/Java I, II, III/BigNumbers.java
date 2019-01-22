/*
 *
 * Trabalhando com números grandes
 *
 */

import java.math.BigDecimal;
import java.math.BigInteger;

public class BigNumbers {

	public static void main(String[] args) {
		
		BigDecimal decimal = new BigDecimal((1 + Math.sqrt(5)) / 2);
		System.out.println(decimal);
		String casas = decimal.toString();
		System.out.println(casas.length() - 2 + " casas decimais");

		BigInteger num = new BigInteger("174295123052");
		BigInteger integer = new BigInteger("10");
		integer = integer.pow(499);
		integer = integer.add(num);
		System.out.println(integer);
		casas = ( integer.add(num) ).toString();
		System.out.println(casas.length() + " digitos");		

	}

}