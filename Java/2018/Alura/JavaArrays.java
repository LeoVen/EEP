/* Status			: Info
 * Created by		: Leonardo Vencovsky
 * Together with 	: niemand / ninguém / nadie / nobody ~~~~~~
 * Date				: 19/01/2018
 * Editor			: Sublime Text 3
 * Inspiration 		: Alura [www.alura.com.br] Java II : Orientação a Objetos aula 01
 * Language			: Portuguese
 *
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