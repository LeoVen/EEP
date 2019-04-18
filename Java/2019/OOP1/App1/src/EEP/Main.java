/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package EEP;

import EEP.App1.models.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

/**
 *
 * @author lvenk
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {

        List<Pessoa> pessoas = Arrays.asList(
            new Pessoa("Vitao", new Date(1998, 06, 27), 1.85),
            new Pessoa("Du", new Date(1999, 2, 18), 1.95),
            new Pessoa("Leo", new Date(1997, 9, 26), 1.93),
            new Pessoa("Yan", new Date(1998, 7, 15), 1.75),
            new Pessoa("Igor", new Date(1998, 8, 4), 1.76)
        );

        for (Pessoa p : pessoas) {
            System.out.println(p);
        }
        
        Animal a = new Cachorro();

        System.out.println(a.getEspecie());
        a.chamar();
        
        Conta c = new Conta(1000.0);
        
        c.sacar(500.0);
        
        System.out.println(c.getSalario());
        
        try {
            c.sacar(1000.0);
        } catch(Exception e) {
            System.out.println(e.getMessage());
            throw e;
        }
    }
}
