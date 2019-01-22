/*
 * Usando a classe Runtime
 *
 */

import java.io.IOException;
import java.lang.Exception;

public class RuntimeExample {

	public static void main(String[] args) throws IOException{

		try {
			Process process = Runtime.getRuntime().exec("ping 8.8.8.8");
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}

}