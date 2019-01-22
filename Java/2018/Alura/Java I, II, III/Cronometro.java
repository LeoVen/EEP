/*
 *
 * Cronometrando operações.
 *
 */

import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;

public class Cronometro {

	public static void main(String[] args) {
		
		System.out.println("Iniciando...");
        Collection<Integer> array = new ArrayList<Integer>();
        List<Integer> lista = new LinkedList<>();

        int total = 500000;

        // Pegando o tempo
        long inicio = System.currentTimeMillis();

        for (int i = 0; i < total; i++) {
            array.add(i);
        }

        /*for (int i = 0; i < total; i++) {
            array.contains(i);
        }*/

        // Tempo gasto
        long fim = System.currentTimeMillis();
        long tempo = fim - inicio;
        System.out.println("Tempo gasto: " + tempo + " milisegundos (ArrayList)");

        // Testando agora com LinkedList
        inicio = System.currentTimeMillis();

        for (int i = 0; i < total; i++) {
            lista.add(0, i);
        }

        fim = System.currentTimeMillis();
        tempo = fim - inicio;
        System.out.println("Tempo gasto: " + tempo + " milisegundos (LinkedList)");

	}

}