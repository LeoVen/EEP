/*
 *
 * Meios de percorrer um array
 *
 */

public class JavaArrays {

	public static void main(String[] args) {

		//Existem dois jeitos de percorrer um array
		for (int i = 0; i < args.length; i++) {
			System.out.println(args[i]);
		}
		System.out.print("\n");
		//Ou por outro método
		for (String pos : args) {
			System.out.println(pos);
		}
	}

}