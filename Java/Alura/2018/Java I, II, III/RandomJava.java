/*
 *
 * Usando Random
 *
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Random;


public class RandomJava {

	public static void main(String[] args) {

		List<Conta> contas = new ArrayList<Conta>();
	    Random random = new Random();
	    Names names = new Names();

	    // Usando random para criar 100 contas com valores aleatórios
	    for (int i = 0; i < 100; i++) {
	    	contas.add(new Conta(names.getName(random.nextInt(names.getSize())), random.nextDouble() * random.nextInt(10000)));
	    }

	    // Sorting
	    Collections.sort(contas);

	    // Imprimindo em ordem
	    for (Conta conta : contas) {
	      System.out.println(conta.getContaInfo());
	    }

	}

}


class Conta implements Comparable<Conta> {

	private String nome;
	private double saldo;

	public Conta(String nome) {
		this.nome = nome;
	}

	public Conta(String nome, double saldo) {
		this.nome = nome;
		this.saldo = saldo;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

	public String getNome() {
		return this.nome;
	}

	public double getSaldo() {
		return this.saldo;
	}

	@Override
	public int compareTo(Conta outra) {
        if ( this.getSaldo() > outra.getSaldo()) return 1;
        else if ( this.getSaldo() < outra.getSaldo()) return -1;
        else return 0;
    }

    public String getContaInfo() {
    	return this.nome + ": " + this.saldo;
    }

}