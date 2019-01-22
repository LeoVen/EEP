/*
 *
 * Input e Output no java
 *
 * InputStream -----Byte-----> InputStreamReader -----Char-----> BufferedReader ----String---->
 *
 * OutputStream <-----Byte----- OutputStreamWriter <-----Char----- BufferedWriter <----String----
 *
 */

import java.io.*;

public class JavaIO {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		InputStream is = new FileInputStream("Input.txt");
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);

		OutputStream os = new FileOutputStream("Output.txt");
		OutputStreamWriter osw = new OutputStreamWriter(os);
		BufferedWriter bw = new BufferedWriter(osw);

		/*
		 * Aqui podemos manipular os arquivos usando .readLine e .append()
		 * Conferir outros métodos na documentação
		 * 
		 */

		//Depois é preciso fechar

		br.close();
		bw.close();

		//Podemos usar também Scanner e PrintStream para ler e escrever respectivamente

		//Pode ser escrito tambem de maneira mais compacta:

		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("Input.txt")));

		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Output.txt")));

		reader.close();
		writer.close();

	}

}