/*
 * Demonstrando Try, Catch e Finally e o fluxo do programa
 *
 * Observe que o programa não passou por Main 02 End porque houve
 * uma exception. Assim, o programa irá pular todo até que tenha um
 * catch e então seguirá normalmente.
 *
 * É possível também usar throw exception para jogar um exceção quando
 * alguma coisa acontecer. Veja exemplo 2.
 * 
 * O finally é particularmente importante quando estamos lidando com
 * recursos externos, como arquivos e banco de dados. Ele sempre
 * será executado independente do sucesso ou da falha na execução do
 * código.
 *
 * Se abrimos um arquivo, e no meio do processamento dele, algo aconteceu
 * e uma exceção ocorreu, precisamos fechá-lo do mesmo jeito. A mesma
 * coisa para conexão com o banco de dados: independente do que acontece,
 * precisamos fechar a conexão ao final.
 *
 */

public class TryCatch {

	public static void main(String[] args) {
		System.out.println("Main Start");

		//Exemplo 01
		main_01();

		System.out.println("Main End");

		/*
		 * Exemplo 02
		 * Se mandarmos sacar uma quantia maior do que temos na conta
		 * voltará um exception
		 */

		Conta rafael = new Conta("Rafael");
		rafael.setSaldo(345.0);
		try {
			rafael.sacarDinheiro(400.0);	
		} catch(RuntimeException e) {
			System.out.println("TryCatch saldo Insuficiente here!");
		}
		

	}

	private static void main_01() {
		System.out.println("Main 01 Start");
		try {
			main_02();
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Index out of bounds exception here!");
		}

		System.out.println("Main 01 End");
	}

	private static void main_02() {
		System.out.println("Main 02 Start");

		int[] list = new int[5];
		for (int i = 0; i < 6; i++) {
			list[i] = i * 2;
		}

		System.out.println("Main 02 End");
	}

}

class Conta {

	private String nome;
	private double saldo;

	public Conta(String nome) {
		this.nome = nome;
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

	public void sacarDinheiro(double quantidade) {

		if (this.saldo >= quantidade) {
			this.saldo -= quantidade;
		} else {
			throw new RuntimeException("Saldo Insuficiente");
		}

	}

}