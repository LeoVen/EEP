/*
 *
 * Trabalhando com a noção de classes e funções abstratas
 *
 * Classes :
 * Uma classe abstrata faz com que ela não pode ser instanciada, apenas extendida por outras classes
 * e então instanciada.
 *
 * Métodos :
 * Um método abstrato faz com que as subclasses sejam obrigadas a terem esse método e preenchê-lo
 * a não ser que a classe que a extende também seja abstrata.
 *
 * Variáveis
 * Note que variáveis não podem ser abstratas.
 *
 */

/*
 * A classe shape é abstrata porque não há motivo de instanciá-la pois ela é apenas um modelo de 
 * formas que irão depois extender-se a ela.
 * 
 * O método whoAmI() é abstrato também pois ele só irá tomar forma assim que as outras classes a
 * criarem.
 *
 * Note que para que uma classe tenha um método abstrato é preciso que a mesma seja abstrata também.
 *
 */
public class Abstract {

	public static void main(String[] args) {

		Draw canvas = new Draw();

		Shape triangulo = new RegularTriangle(2);
		triangulo.printAll();
		Shape quadrado = new RegularSquare(4);
		quadrado.printAll();
		Shape hexagono = new RegularHexagon(1.4);
		hexagono.printAll();

		triangulo.whoAmI();
		canvas.drawShape(triangulo);
		quadrado.whoAmI();
		canvas.drawShape(quadrado);
		hexagono.whoAmI();
		canvas.drawShape(hexagono);

		//Criando um vetor. Perceba que estamos instanciando um vetor, e não Shape
		Shape[] mosaic = new Shape[10];

		//Agora sim estamos instanciando as classes, porém dessa vez com as subclasses pois Shape é abstract
		for (Shape i : mosaic) {
			i = new RegularSquare(2);
		}

		Ghost ghastly = new Ghost("Ghastly");
		Poltergeist peeves = new Poltergeist("Peeves");

		ghastly.whoAmI();
		canvas.drawShape(ghastly);
		peeves.whoAmI();
		canvas.drawShape(peeves);


	}

}

abstract class Shape {

	protected long corners;
	protected double area;
	protected double perimeter;
	protected String name;

	protected Shape(long corners, double ss, String name) {
		this.corners = corners;
		this.perimeter = corners * ss;
		this.name = name;
	}

	public long getCorners() {
		return corners;
	}

	public double getArea() {
		return area;
	}

	public double getPerimeter() {
		return perimeter;
	}

	public void printAll() {
		System.out.println("\n" + this.name + " : ----------");
		System.out.println("Area : " + this.area);
		System.out.println("Perimeter : " + this.perimeter);
		System.out.println("Corners : " + this.corners);
		System.out.println("\n");
	}

	// Exemplo de método abstract
	public abstract void whoAmI();

}

class RegularTriangle extends Shape {

	public RegularTriangle(double ss) {
		super(3, ss, "Regular Triangle");
		this.area = ss * ss * Math.sqrt(3) / 4;
	}

	public void whoAmI() {
		System.out.println("I'm a Triangle!");
	}

}

class RegularSquare extends Shape {

	public RegularSquare(double ss) {
		super(4, ss, "Regular Square");
		this.area = ss * ss;
	}

	public void whoAmI() {
		System.out.println("I'm a Square!");
	}

}


class RegularHexagon extends Shape {

	public RegularHexagon(double ss) {
		super(6, ss, "Regular Hexagon");
		this.area = 3 * Math.sqrt(3) * ss * ss / 2;
	}

	public void whoAmI() {
		System.out.println("I'm a Hexagon!");
	}

}


class Draw {

	public void drawShape(Shape shape) {
		if (shape.corners == 3) { // Triangle
			System.out.println("\n");
			System.out.println("             /\\");
			System.out.println("            /  \\");
			System.out.println("           /    \\");
			System.out.println("          /      \\");
			System.out.println("         /        \\");
			System.out.println("        /          \\");
			System.out.println("       /            \\");
			System.out.println("      /              \\");
			System.out.println("     /                \\");
			System.out.println("    /__________________\\");
			System.out.println("\n");
		} else if (shape.corners == 4) { // Square
			System.out.println("\n");
			System.out.println("     ____________________");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |                    |");
			System.out.println("    |____________________|");
			System.out.println("\n");
		} else if (shape.corners == 6) { // Hexagon
			System.out.println("\n");
			System.out.println("        ____________");
			System.out.println("       /            \\");
			System.out.println("      /              \\");
			System.out.println("     /                \\");
			System.out.println("    |                  |");
			System.out.println("    |                  |");
			System.out.println("    |                  |");
			System.out.println("     \\                /");
			System.out.println("      \\              /");
			System.out.println("       \\____________/");
			System.out.println("\n");
		} else {
			System.out.println("\nError! I don't have this shape to draw ..\n\n");
		}
	}

}

//Note que esta classe pode extender Shape sem sobrescrever a classe Shape pois ela também é abstrata
abstract class Spirit extends Shape {

	public Spirit(String name) {
		super(0, 0, name);
		this.area = 0;
	}

	public abstract void sayHello();

}

//Já esta classe não é abstrata, então ela precisa sobrescrever todos os métodos abstratos
class Ghost extends Spirit {

	public Ghost(String name) {
		super(name);
	}

	public void sayHello() {
		System.out.println("I'm a ghost and I don't have shape!");
	}

	public void whoAmI() {
		System.out.println("Hi! My name is " + this.name + " and I'm a ghost ..");
	}

}

class Poltergeist extends Spirit {

	public Poltergeist(String name) {
		super(name);
	}

	public void sayHello() {
		System.out.println("I'm a Poltergeist and I don't have shape!");
	}

	public void whoAmI() {
		System.out.println("Hi! My name is " + this.name + " and I'm a Poltergeist ..");
	}

}