/*
 *
 * Conceitos de orientação a objetos mais avançados
 *
 * Conceitos vistos :
 * - extends
 * - protected
 * - super
 * - polymorphism
 *
 * - Extends
 * Por exemplo uma classe Dog com métodos latir(), correr(), comer(), etc e é uma
 * classe geral onde podem haver outras classes como Chihuahua que extends Dog e
 * nessa classe podemos chamar os métodos previamente ditos. Neste caso Dog é a
 * superclass e Chihuahua é uma Subclass.
 *
 * - Protected
 * Quando uma variável ou uma função é privada, somente aquela classe pode acessá-la,
 * mas quando ela é protected todas as classes que se extendem a ela também podem
 * acessá-la.
 *
 * - Super
 * Quando queremos chamar um método a partir de uma Subclass que foi sobrescrito por
 * ela, ou seja, o método original na Superclass, devemos usar a palavra chave
 * super.nomeDoMetodo();
 *
 * - Polymorphism
 * É a capacidade de uma classe apontar para outro objeto. Observe que a classe não
 * irá se "transformar" para uma outra classe, mas sim apontar para métodos diferentes.
 * Como exemplo: se a classe Chihuahua come() "pouco" e a classe Labrador come() "muito"
 * e fazermos um polimorfismo de uma variável que antes era Chihuahua para Labrador, ao 
 * chamarmos o método come(), retornará "muito" e não "pouco" como seria antes.
 *
 */


public class Extends {

	public static void main(String[] args) {

		Control control = new Control();
		
		//Exemplo de variáveis protected
		System.out.println("\n\nFuncionario:");

		Funcionario joaquim = new Funcionario("Joaquim");
		joaquim.setSalario(1000.0);
		System.out.println(joaquim.getSalario());
		control.setBonusTotal(joaquim);
		System.out.println("Com bonus:");
		System.out.println(joaquim.getSalario());

		//Exemplo de Extends
		System.out.println("\n\nGerente:");

		Gerente rafael = new Gerente("Rafael");
		rafael.setSalario(1000.0);
		System.out.println(rafael.getSalario());
		control.setBonusTotal(rafael);
		System.out.println("Com bonus:");
		System.out.println(rafael.getSalario());

		System.out.println("\n\nDesenvolvedor:");

		Desenvolvedor lucas = new Desenvolvedor("Lucas");
		lucas.setSalario(1000.0);
		System.out.println(lucas.getSalario());
		control.setBonusTotal(lucas);
		System.out.println("Com bonus:");
		System.out.println(lucas.getSalario());

		System.out.println("\n\nBonus dado total:");
		System.out.println(control.getBonusTotal());

		//Usando super para chamar um método da Superclass
		System.out.println("\n");
		joaquim.reclamarDoTrabalho();
		rafael.reclamar();
		lucas.reclamar();

		//Exemplos de polymorphism
		Gerente gerente = new Gerente("Marcos");
		Funcionario funcionario = gerente;
		funcionario.gritar();

		Desenvolvedor desenvolvedor = new Desenvolvedor("Rick");
		Funcionario outroFuncionario = desenvolvedor;
		outroFuncionario.gritar();

	}

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

	public double getBonus() {
		this.salario *= 1.1;
		return salario;
	}

	public double getSalario() {
		return this.salario;
	}

	public void reclamarDoTrabalho() {
		System.out.println("I hate my job!");
	}

	public void gritar() {
		System.out.println("ESTOU COM MUITO SONO");
	}

}

class Gerente extends Funcionario {

	public Gerente(String nome) {
		super(nome);
	}

	public double getBonus() {
		this.salario *= 1.3;
		return this.salario;
	}

	public void reclamar() {
		super.reclamarDoTrabalho();
	}

	public void gritar() {
		System.out.println("EU SOU GERENTE E MANDO EM VOCES");
	}

}

class Desenvolvedor extends Funcionario {

	public Desenvolvedor(String nome) {
		super(nome);
	}

	public double getBonus() {
		this.salario *= 1.2;
		return this.salario;
	}

	public void reclamar() {
		super.reclamarDoTrabalho();
	}

	public void gritar() {
		System.out.println("PORQUE DIABOS ESSE CODIGO NAO ESTA COMPILANDO");
	}

}

class Control {

	double bonusTotal = 0;

	public void setBonusTotal(Funcionario f) {
		this.bonusTotal += ( f.getSalario() - f.getBonus() ) * -1;
	}

	public double getBonusTotal() {
		return this.bonusTotal;
	}

}
