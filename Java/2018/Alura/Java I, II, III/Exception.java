/*
 * Aprendendo a tratar exceptions
 *
 * Checked vs Unchecked exceptions
 * 
 * As exceptions checked são conferidas na hora da compilação e por isso
 * precisam ser obrigatoriamente tratadas ou especificar a exception com
 * throws. Já as exceptions unchecked não são conferidas na hora da compilação
 * e por isso o compilador não nos força a tratá-las. As classes de Exceptions
 * dentro de Error e RuntimeException (e suas subclasses) são unchecked
 * exceptions.
 *
 * Catch :
 * É possível também ter mais de um catch. Possivelmente um para cada tipo
 * de exception esperada que ocorra.
 *
 * Finally :
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

public class Exception {

	public static void main(String[] args) {
		System.out.println("Main Start");

		//Exemplo 01
		main_01();

		System.out.println("Main End");

		System.out.println("\nExemplo 2\n");

		/*
		 * Exemplo 02
		 * Se mandarmos sacar uma quantia maior do que temos na conta
		 * voltará um exception
		 */

		Conta rafael = new Conta("Rafael");
		rafael.setSaldo(345.0);
		try {
			rafael.sacarDinheiro(400.0);	
		}
		catch(myRuntimeException e) {
			System.out.println(e.getMessage() + e.getSaldoAtual());
		}
		catch (myException e) {
			System.out.println("Um outro erro qualquer");
		}

		try {
			rafael.depositarDinheiro(-200.0);
		} catch (myException e) {
			System.out.println(e.getLog());
		} finally {
			System.out.println("\nFinalmente terminamos ..");
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
		} else if (this.saldo < quantidade && quantidade > 0) {
			throw new myRuntimeException(this.saldo, "Saldo Insuficiente ");
		} 

	}

	public void depositarDinheiro(double quantidade) {
		
		if (quantidade > 0) {
			this.saldo += quantidade;
		} else {
			throw new myException(	"Quantidade a sacar nao pode ser negativa", 
									quantidade);
		}
	}

}

class myRuntimeException extends RuntimeException {

	private final double saldoAtual;
	private final String message;

	public myRuntimeException(double saldo, String msg) {
		this.saldoAtual = saldo;
		this.message = msg;
	}

	public double getSaldoAtual() {
		return this.saldoAtual;
	}

	public String getMessage() {
		return this.message;
	}

	public String getLog() {
		return "O saldo e insuficiente pois voce tem apenas " +
				this.saldoAtual +
				" reais";
	}

}

class myException extends IllegalArgumentException {

	private final String message;
	private final double quantidade;

	public myException(String msg, double numero) {
		this.message = msg;
		this.quantidade = numero;
	}

	public String getMessage() {
		return this.message;
	}

	public String getLog() {
		return this.message + " (" + this.quantidade + ")";
	}

}