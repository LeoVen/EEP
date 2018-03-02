/* 
 * Finalmente descobri como criar um vetor de objetos
 *
 * (at this time I was [ still am ..? ] a noob at Java programming)
 *  
 * Este código serve para exemplificar como funciona vetores
 * de objetos dentro de uma classe. São minhas primeiras tentativas
 * de fazê-lo ...
 * É possível observar também que o método length() em
 * uma String retorna o tamanho da String porém num vetor
 * não é usado um método e sim uma constante pois o tamnho
 * de um vetor é constante, já a de uma String pode variar
 *
 * PS:
 * Onde está "Lerite" na verdade quis dizer holerite, que 
 * na verdade está fora do contesto pois pensei em Cartão
 * Ponto ... Apenas ignore and go with the flow ~~~~~~
 */

//Note que a classe public deve ter o mesmo nome que o arquivo .java
public class EmpresaJava {

	public static void main(String[] args) {

		//Criando uma lista de nomes apenas para diversidade
		String[] listaNomes = new String[10];
		listaNomes[0] = "Leonardo";
		listaNomes[1] = "Jonas";
		listaNomes[2] = "Alfredo";
		listaNomes[3] = "Guilherme";
		listaNomes[4] = "Amanda";
		listaNomes[5] = "Yasmin";
		listaNomes[6] = "Rafael";
		listaNomes[7] = "Enzo";
		listaNomes[8] = "Ronaldo";
		listaNomes[9] = "Elizabeth";

		//Instanciando uma Empresa
		Data data = new Data(20, 4, 1967);
		Empresa alura = new Empresa(156445.93f, "4433-123-14-41.441", data);
		alura.listaDeFuncionarios = new Funcionario[10];

		//Instanciando funcionários e lerites
		for (int i = 0; i < 10; i++) {			 

			boolean trab = true;
			if (i % 4 == 0) {
				trab = false;
			}
			Data nascimento = new Data(i+4, i, 2000-i);
			alura.listaDeFuncionarios[i] = new Funcionario(	listaNomes[i],
															i + 10,
															nascimento,
															listaNomes[i].length() * 100.12f,
															trab);
			//Instanciando lerites
			alura.listaDeFuncionarios[i].lerite = new Data[5];
			for (int j = 0; j < 5; j++) {
				alura.listaDeFuncionarios[i].lerite[j] = new Data(j+i+1, 1, 2018);
			}

		}


		//Agora descrevendo a empresa como um todo
		alura.descreverEmpresa();


	}

}


class Empresa {

	Funcionario[] listaDeFuncionarios;
	String cnpj;
	float capitalTotal;
	Data dataDeCriacao;

	public Empresa(float capital, String cnpj, Data data) {

		this.capitalTotal = capital;
		this.cnpj = cnpj;
		this.dataDeCriacao = data;

	}

	void descreverEmpresa() {

		for (int i = 0; i < listaDeFuncionarios.length; i++) {
			this.listaDeFuncionarios[i].descreverFuncionario();
		}

	}

}


class Funcionario {

	String nome;
	int idade;
	Data nascimento;
	float salario;
	Data[] lerite;
	boolean trabalhaNaEmpresa;

	public Funcionario(String nome, int idade, Data nascimento, float salario, boolean trab) {
		this.nome = nome;
		this.idade = idade;
		this. nascimento = nascimento;
		this.salario = salario;
		this.trabalhaNaEmpresa = trab;
	}

	void descreverFuncionario() {
		System.out.println(" ");
		System.out.println("< -------------------- >");
		System.out.println("Nome: " + this.nome);
		System.out.println("Idade: " + this.idade);
		System.out.println("Data de nascimento: " + this.dataString(this.nascimento));
		System.out.println("Salario: " + this.salario);
		if (this.trabalhaNaEmpresa) {
			System.out.println("Este Funcionario trabalha na sua empresa!");
		} else {
			System.out.println("Este Funcionario nao trabalha na sua empresa!");
		}
		System.out.println("");
		System.out.println("LERITE:");
		this.printLerite();
		System.out.println("< -------------------- >");
		System.out.print("\n\n");
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