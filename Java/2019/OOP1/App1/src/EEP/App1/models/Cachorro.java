/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package EEP.App1.models;

/**
 *
 * @author lvenk
 */
public class Cachorro extends Animal {

    @Override
    public void chamar() {
        System.out.println("Cachorro");
    }
    
    public void latir() {
        System.out.println("Auf Auf");
    }
    
}
