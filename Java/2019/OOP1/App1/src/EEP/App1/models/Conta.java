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
public class Conta {
    private double salario;

    public Conta(double salario) {
            this.salario = salario;
    }

    public double getSalario() {
            return salario;
    }

    public void sacar(double quantidade) throws Exception {
            if (quantidade > salario) {
                    throw new Exception("Voce nao e tao rico assim");
            }

            salario -= quantidade;
    }
}
