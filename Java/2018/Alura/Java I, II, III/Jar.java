/*
 * Jar e Javadoc
 *
 * Jar
 * O Java Archive possui um conjunto de classes (e arquivos de configurações)
 * compactados, no estilo de um arquivo zip. Ele também pode ser tratado como
 * um executável se for informado em um arquivo Manifest.txt qual classe deve
 * ser a primeira a ser executada.
 * Dentro de Manifest.txt devemos por:
 *     Main-Class: br.com.empresa.projeto.pacote.NomeDaClassePrincipal
 *     
 * Não esquecer de colocar mais uma linha em branco! É importante pois ela pode
 * prevenir bugs.
 * Incluindo um manifesto no arquivo .jar :
 *     jar cfm NomeProjeto.jar Manifest.txt caminho/do/arquivo/
 *
 * Gerando um .jar:
 *     jar -cvf NomeDoArquivo.jar br/com/nomedaempresa/projeto/pacote/*.class
 * É possível também informar mais de um pacote, separando-os com um espaço:
 *     jar -cvf NomeDoArquivo.jar br/com/empresa/projeto/pacote01/*.class br/com/empresa/projeto/pacote02/*.class 
 * Para rodar um .jar usamos a flag -jar com java:
 *     java -jar caminho/do/arquivo/Arquivo.jar
 *
 * Para mais informações ver a documentação do comando jar.
 * 
 * Existem várias ferramentas para automatizar o deploy do projeto. Entre elas:
 * ANT e MAVEN
 * Ambos do grupo Apache.
 * É possível também gerar .jar por meio das IDE.
 *
 * Javadoc
 * O Javadoc é uma documentação que descreve as classes, métodos e variáveis do
 * projeto. Métodos e atributos privados não aparecem pois o objetivo do Javadoc
 * é documentar o que sua classe faz e não como ela faz. Também é possível gerar
 * o Javadoc a partir do prompt com o comando javadoc:
 *     javadoc Jar.java
 * E se queremos colocá-lo em uma determinada pasta:
 *     javadoc -d DataClassDoc Data.java
 *
 * Adicionando comentários no código que irão aparecer no Javadoc:
 * Deve-se começar com /** e terminar com */

 /**
 * Exemplo de Javadoc
 * Dentro de um Javadoc existem as seguintes tags:
 * 
 * @author NomeDoAutor (Apenas para classes e interfaces)
 * @version V01.024 (Apenas para classes e interfaces)
 * @param 
 * @throws Exception
 * @see
 * @since
 * @serial
 * @deprecated
 *
 */

 /*
 *
 * Ver mais sobre jar e javadoc !
 *
 */

public class Jar {

	protected String helloWorld = "Hello World!";
	protected String helloUniverse = "Hello Universe!";

	public static void main(String[] args) {
		
		System.out.println("Hello Jar!");

	}

}