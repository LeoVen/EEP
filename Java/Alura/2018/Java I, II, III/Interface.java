/*
 * Trabalhando com Implements e Interfaces
 *
 * Interface :
 * É uma classe abstrata que contém somente métodos abstratos.
 *
 * Implements :
 * Usamos implements para implementar os métodos de uma interface. É possível
 * implementar mais de uma interface separando-as por uma vírgula.
 *
 * Podemos usar uma interface como parâmetro. Ou seja, apenas as classes que
 * possuem essa interface (os métodos implementados) é que poderão ser enviadas
 * como parâmetro.
 * Quem está acessando uma interface não tem a menor idéia de quem exatamente
 * é o objeto o qual a referência está apontando. Mas com certeza o objeto tem
 * os métodos que busca.
 * 
 *
 *
 */

/*
 *          Herança          x     Interface
 *                           x
 * Herda    Atributos        x     Certeza que o método existe
 *          Métodos          x
 *          Implementações   x
 *
 *
 */

import java.util.Scanner;

public class Interface {

	public static void main(String[] args) {

		Banco brasil = new Banco();

		Gerente gerente = new Gerente("Leonardo");
		Diretor diretor = new Diretor("Rafael");
		Cliente fulano = new Cliente("Fulano", 25);

		//É possível fazer também pois AcessoAoBanco é implementado em Gerente
		AcessoAoBanco outroGerente = new Gerente("Enzo");

		brasil.autentica(outroGerente);
		brasil.autentica(diretor);
		brasil.autentica(fulano);

	}

}

class Banco {

	public void autentica(AcessoAoBanco f) {

		int senha = 1234;

		if (f.autentica(senha) == true) {
			System.out.println("Bem vindo ao sistema bancario\n");
		} else {
			System.out.println("Senha incorreta. Saindo...\n");
		}

	}

}

//Em uma interface todos os métodos são abstratos !
interface AcessoAoBanco {

	/* abstract */ boolean autentica(int senha);

}

class Funcionario {

	protected double salario;
	protected String nome;

	public Funcionario(String nome) {
		this.nome = nome;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getSalario() {
		return this.salario;
	}

	public String getNome() {
		return this.nome;
	}

}

class Diretor extends Funcionario implements AcessoAoBanco {

	public Diretor(String nome) {
		super(nome);
	}

	@Override // Usado por best practices
	public boolean autentica(int senha) {
		System.out.println("Entrando como Diretor...");
		System.out.println("Digite a senha");
		Scanner sc = new Scanner(System.in);
		int inputSenha = sc.nextInt();

		if (inputSenha == senha) {
			return true;
		} else {
			return false;
		}
	}

}

class Gerente extends Funcionario implements AcessoAoBanco {

	public Gerente(String nome) {
		super(nome);
	}

	@Override // Usado por best practices
	public boolean autentica(int senha) {
		System.out.println("Entrando como Gerente...");
		System.out.println("Digite a senha");
		Scanner sc = new Scanner(System.in);
		int inputSenha = sc.nextInt();

		if (inputSenha == senha) {
			return true;
		} else {
			return false;
		}
	}

}

class Engenheiro extends Funcionario {

	public Engenheiro(String nome) {
		super(nome);
	}

}

class Secretario extends Funcionario {

	public Secretario(String nome) {
		super(nome);
	}

}

class Cliente implements AcessoAoBanco {

	private String name;
	private long age;

	public Cliente(String nome, long idade) {
		this.name = nome;
		this.age = idade;
	}

	@Override // Usado por best practices
	public boolean autentica(int senha) {
		System.out.println("Entrando como Cliente...");
		System.out.println("Digite a senha");
		Scanner sc = new Scanner(System.in);
		int inputSenha = sc.nextInt();

		if (inputSenha == senha) {
			return true;
		} else {
			return false;
		}
	}

}