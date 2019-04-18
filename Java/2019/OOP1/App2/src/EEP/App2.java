/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package EEP;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

/**
 *
 * @author lvenk
 */
public class App2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Exercises:
        // Sum fourth row
        // How many rows were sumed
        // Max value
        // Min value
        // Average

        // This file must be located at the parent folder of this project
        String fileName = "POO_Aula7_dados.csv";
        
        ArrayList<Double> dlist = new ArrayList<>();
        
        FileReader reader;
        BufferedReader buffer;
        
        try {
            reader = new FileReader(fileName);
            buffer = new BufferedReader(reader);
            
            String row = buffer.readLine();
            
            while (row != null) {
                StringTokenizer tok = new StringTokenizer(row, "|");
                for (int i = 0; i < 3; i++)
                    tok.nextToken();

                dlist.add(Double.parseDouble(tok.nextToken()));

                row = buffer.readLine();
            }
        } catch (IOException | NumberFormatException | 
                 NoSuchElementException ex) {
            System.out.println("Woops, something went wrong :(");
        }

        try {
            System.out.println("Total sum: " + dlist.stream()
                                                    .mapToDouble(a -> a)
                                                    .sum());
        System.out.println("Average  : " + dlist.stream()
                                                .mapToDouble(a -> a)
                                                .average()
                                                .getAsDouble());
        } catch (NoSuchElementException ex) {
            System.out.println("Woops, something went wrong :(");
        }

        System.out.println("Max value: " + Collections.max(dlist));
        System.out.println("Min value: " + Collections.min(dlist));
        System.out.println("Total de registros: " + dlist.size());
    }
    
}
