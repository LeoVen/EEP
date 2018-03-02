/*
 * Entendendo java.lang
 *
 * Object
 * Todas as classes já extendem a classe Object. Isso é muito bomquando queremos
 * que um método receba qualquer classe. Assim, a classe Object é a mais genérica
 * fazendo com que um método que a tem como parâmetro possa receber qualquer
 * classe. O mesmo pode ser feito com o retorno. Se é retornado um Object então
 * esse método pode retornar qualquer classe.
 *
 * Casting
 * Casting serve para garantir ao compilador que se recebemos uma classe genérica,
 * por exemplo Object, esperamos uma classe (NomeDaClasse) e para que não ocorra
 * um erro na hora de compilar. Porém se for recebido uma classe além daquela que
 * foi apontada, ocorrerá um erro.
 *
 * String
 * Strings são imutáveis. Nunca mudam de valor. Em sua classe padrão existe o
 * método string.replace("r", "g"); que troca todos os 'r' por 'g'. Veja o exemplo.
 * Ver os métodos de String com mais detalhes.
 *
 * System
 * Ver com mais detalhes a classe System na documentação.
 *
 * Wrappers
 * Os classes wrapper são usadas para converter qualquer tipo de dado em um objeto.
 * Os tipos primitivos não são objetos, mas as vezes é preciso converter esses
 * tipos primitivos em classes. O tipo Wrapper basicamente embrulham um tipo
 * primitivo em um objeto, disponibilizando vários métodos úteis como o parse.
 * Ver com mais detalhes cada classe com mais detalhes.
 *
 * StringBuffer
 * Quando modificamos uma string muitas vezes é melhor usar esta classe, pois,
 * diferente da classe String, ela é mutável (mas não é thread-safe).
 *
 * Math
 * Uma biblioteca com várias funções matemáticas. Ver com mais detalhes.
 *
 */

import java.io.IOException;

public class JavaLang {

	public static void main(String[] args) {
		
		System.out.println("Metodo main");

		GuardaObjetos trunk = new GuardaObjetos();

		Data data01 = new Data(10, 10, 2010);
		Data data02 = new Data(10, 10, 2010);
		Conta joao = new Conta("Joao Anibal");

		joao.setSaldo(500.9);

		//Data vai na posição 0
		trunk.guardarObjeto(data01);
		trunk.guardarObjeto(joao);

		//Guardando um inteiro a partir de um wrapper
		int k = 12;
		Integer x = new Integer(k);

		//Passando um objeto Integer como argumento
		trunk.guardarObjeto(x);

		//Recebendo um Integer
		Integer y = (Integer) trunk.pegaObjeto(2);

		//Escrevendo como se fosse um inteiro comum (com ajuda do autoboxing)
		//O autoboxing só é disponível a partir do Java 5.0
		System.out.println("Integer: " + y.toString());

		/*
		 * Casting .. garantindo ao compilador que o objeto é do tipo Data
		 *
		 * O exemplo abaixo não compila :
		 *     Conta pos00InsideTrunk = trunk.pegaObjeto(0);
		 * Não seria possível pois não é garantido que retorne um objeto do
		 * tipo Data, mas com o casting garantimos ao compilador que sim será
		 * retornado um objeto do tipo Data
		*/
		Data pos00InsideTrunk = (Data) trunk.pegaObjeto(0);
		Conta pos01InsideTrunk = (Conta) trunk.pegaObjeto(1);

		System.out.println(pos00InsideTrunk.getStringData());

		System.out.println("Data01 e Data02 sao iguais? " + data01.equals(data02));

		//Exemplo de replace
		//Note que strings são imutáveis
		String leo = "Leonardo";
		leo.replace("o", "u");
		System.out.println("Note que nao muda: " + leo);
		leo = leo.replace("o", "u");
		System.out.println("Agora muda: " + leo);

		int i = 0;

		System.out.println("Lendo um byte");
		try {
			i = System.in.read();	
		} catch(IOException e) {
			e.printStackTrace();
		} finally {
			System.out.println(i);
		}


	}

}

class GuardaObjetos {

	private Object[] objetos;
	private int posLivre;

	public GuardaObjetos() {
		objetos = new Object[100];
		posLivre = 0;
	}

	public void guardarObjeto(Object obj) {
		objetos[posLivre] = obj;
		posLivre++;
	}

	public Object pegaObjeto(int pos) {
		return objetos[pos];
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

}

