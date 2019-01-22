/*
 * Exemplificando como funciona um vetor de objetos dentro de uma classe
 *
*/

//Note que a classe public deve ter o mesmo nome que o arquivo .java
public class VetorDeObjetos {

	public static void main(String[] args) {

		// * Instanciando uma data com construtor
		Data data = new Data(26, 9, 1997);

		// * Instanciando uma classe funcionario com construtor
		Funcionario f1 = new Funcionario("Leonardo", 20, data, 1367.88f);

		// * Instanciando um vetor do tipo Data dentro de f1 que é da 
		// * classe Funcionario
		f1.lerite = new Data[10];

		// * Instanciando em cada posição do vetor previamente criado
		// * um tipo Data por meio de um construtor
		for (int i = 0; i < 10; i++) {
			f1.lerite[i] = new Data(1+i, 4, 2018);
		}

		// * Escrevendo as propriedades da classe Funcionario inclusive
		// * suas "subclasses"
		f1.descreverFuncionario();

	}

}


class Funcionario {

	String nome;
	int idade;
	Data nascimento;
	float salario;
	Data[] lerite;

	public Funcionario(String nome, int idade, Data nascimento, float salario) {
		this.nome = nome;
		this.idade = idade;
		this. nascimento = nascimento;
		this.salario = salario;
	}

	void descreverFuncionario() {
		System.out.println("Nome: " + this.nome);
		System.out.println("Idade: " + this.idade);
		System.out.println("Data de nascimento: " + this.dataString(this.nascimento));
		System.out.println("Salario: " + this.salario);
		System.out.println("LERITE:");
		this.printLerite();
	}

	String dataString(Data data) {
		return data.dia + "/" + data.mes + "/" + data.ano;
	}

	void printLerite() {
		for (int i = 0; i < this.lerite.length; i++) {
			System.out.println(dataString(this.lerite[i]));
		}
	}

}


class Data {

	int dia, mes, ano;

	public Data(int dia, int mes, int ano) {
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

}