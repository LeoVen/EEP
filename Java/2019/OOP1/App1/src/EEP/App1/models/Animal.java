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
public abstract class Animal {
    public String getEspecie() {
            return new String("Animal");
    }
    public abstract void chamar();
}
