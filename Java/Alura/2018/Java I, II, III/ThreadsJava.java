/*
 *
 * Trabalhando com Threads em java e usando a keyword synchronized
 *
 * Quando uma classe implementa runnable é possível instanciar uma Thread com ela
 * porém uma classe pode também estender a uma classe Thread e assim herdar varios
 * métodos. Porém neste caso, por boas práticas é melhor implementar Runnable
 * apenas para ter a função run(), deixando então de herdar um monte de métodos
 * que não serão utilizados.
 *
 * Scheduler e Context Switch
 * O scheduler é o responsável por escolher qual a próxima Thread será executada e
 * fazer o Context Switch. O estado da Thread é salvo para então depois ser executado
 * depois novamente.
 *
 * Garbage Collector
 * O garbage collector funciona como uma thread responsável por jogar fora todos os 
 * objetos que não estão sendo referenciados por nenhum outro objeto. Seja de maneira
 * direta ou indireta. Uma maneira de fazer isso é instanciar dois objetos e em uma 
 * terceira linha atribuir um objeto ao outro. Porém não é certeza que o garbage
 * collector irá jogar fora aquele objeto. A prática mais comum é atribuir um objeto 
 * a null.
 *
 * Finalizer
 * Finalize é um método que será chamado antes da classe passar pelo Garbage Collector.
 * 
 * Synchronized
 * A palavra chave synchronized serve como uma trava à uma parte do código e tem como
 * parâmetro um objeto. Ela define que só pode haver uma thread acessando aquele código
 * por vez e a referência é o objeto.
 *
 * Ver mais sobre java.util.concurrent
 *
 */

public class ThreadsJava {

	public static void main(String[] args) throws InterruptedException {

		/*

		HelloWorld hw = new HelloWorld();
		LoremIpsum li = new LoremIpsum();

		Thread t1 = new Thread(hw);
		Thread t2 = new Thread(li);

		t1.start();
		t2.start();

		*/

		// Outro problema que pode acontecer é o acesso a variáveis por duas threads diferentes
		Conta c1 = new Conta(500.0);
		FazDeposito act = new FazDeposito(c1);

		Thread t3 = new Thread(act);
		Thread t4 = new Thread(act);

		t3.start();
		t4.start();
		
		t3.sleep(3000);
		t4.sleep(4000);

		t3.join();
		t4.join();

		System.out.println(c1.getSaldo());

		synchro

	}

}

class HelloWorld implements Runnable {

	@Override
	public void run() {
		for (int i = 0; i < 1000; i++) {
			System.out.println("Hello World");	
		}
	}

}

class LoremIpsum implements Runnable {

	@Override
	public void run() {
		for (int j = 0; j < 1000; j++) {
			System.out.println("Lorem ipsum sit amet");
		}
	}

}

class Conta {

	private String nome;
	private double saldo;

	public Conta(String nome) {
		this.nome = nome;
	}

	public Conta(String nome, double saldo) {
		this.nome = nome;
		this.saldo = saldo;
	}

	public Conta(double saldo) {
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

	public synchronized void deposita(double valor) {
		this.saldo += valor;
	}

}

class FazDeposito implements Runnable {

	private Conta conta;
	public FazDeposito(Conta conta) {
		this.conta = conta;
	}

	@Override
	public void run() {
		conta.deposita(100.0);
	}

}

class Account {

    private double saldo;


    public void atualiza(double taxa) {
        synchronized (this) {
            double saldoAtualizado = this.saldo * (1 + taxa);
            this.saldo = saldoAtualizado;            
        }
    }

    public void deposita(double valor) {
        synchronized (this) {
            double novoSaldo = this.saldo + valor;
            this.saldo = novoSaldo;            
        }
    }
}