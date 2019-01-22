/*
 * O que são packages e como importar classes
 *
 * Packages:  
 * Packages são um diretório contendo classes java. É usado para quando usamos
 * classes de um outro desenvolvedor chegaremos ao ponto onde teremos duas
 * classes com o mesmo nome. Os pacotes servem também para diferenciá-las.
 * É preciso em cada classe java especificar a qual pacote ela pertence:
 *     package br.com.caelum.projeto.pacotes;
 * Seguindo o seguinte padrão:
 *     package br.com.nomedaempresa.nomedoprojeto.subpacote;
 *
 * Import:
 * Para usarmos uma classe contida num pacote deveríamos, sempre que ao declará-la
 * escrever:
 *     br.com.caelum.projeto.pacotes.ClasseJava classe = new br.com.caelum.projeto.pacotes.ClasseJava();
 * Para combater isso usamos o import:
 *     import br.com.caelum.projeto.pacotes.ClasseJava;
 * Assim ao chamarmos a classe ClasseJava podemos escrever apenas:
 *     ClasseJava classe = new ClasseJava();
 * É possível importar todas as classes de um pacote de uma vez usando o * :
 *     import java.util.*;
 * 
 * Modificadores:
 * public    : Todas as classes podem acessá-la
 * protected : Todas as classes do mesmo pacote e todas as classes que a extendam podem acessá-la
 * <default> : (sem modificador) o modificador package-private é utilizado implicitamente
 * private   : a própria classe é quem pode acessar seus métodos e atributos
 * package-private : apenas classes do pacote podem acessá-la
 *
 * O java não permite mais de uma classe pública por arquivo, além de que essa
 * classe deve ter o mesmo nome do arquivo.
 *
 *
 */