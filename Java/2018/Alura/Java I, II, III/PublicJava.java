/* 
 * Modificadores de acesso e introdução aos conceitos de OOP
 *
 * Here we'll see the the access modifiers of java at work
 * Private : only code inside the class can have access to the method or variable
 * Public  : any other class has access to this method
 * Static  : this variable or method is the same for every class
 *
 * Java Programming Conventions :
 * getters : getVariable - Returns a private variable. Must have "get" prefix.
 * setters : setVariable - Sets a new value for a private variable. Must have "set" prefix.
 * In case of a boolean variable :
 * isVariable (if it "is" true or false);
 * 
 * Java Concepts :
 * - Encapsulation
 * - Abstraction
 * - Inheritance
 * - Polymorphism
 *
 * Notes:
 *
 * - It is possible to have multiple constructors for a single Class
 * - Constructors must have different quantity of arguments or at
 * 		 least different argument data types
 * - To invoke a constructor inside the class it is used : this()
 * - Static variables don't use this.
 * - To use a static method you must do: Class.method()
 * - Static methods can only use static variables
 */

//This class uses Data.java so you must have it compiled
public class PublicJava {

	public static void main(String[] args) {

		//Creating a full account
		Account alura = new Account("Alura", 5622.98, 10000.0, 1000.0);

		//Creating a partial account
		Account leo = new Account("Leonardo", 762.23);

		//Creating an account with no initial balance
		Account nona = new Account("Nona");

		System.out.println(leo.getBalance());
		System.out.println(leo.getOwner());

		alura.cashWithdrawal(244.22);
		System.out.println("Cash Withdrawal: " + alura.getBalance());
		alura.creditPayment(333.89);
		System.out.println("Credit Payment: " + alura.getBalance());
		alura.cashWithdrawal(309.39);
		System.out.println("Cash Withdrawal: " + alura.getBalance());

		//Setting a full account for leo
		leo.setFullAccount(400.0, 600.0);

		//Trying to set a full account again
		alura.setFullAccount(5000.0, 1200.0);

		alura.cashWithdrawal(6000);

		Data date = new Data(9, 9, 2009);
		System.out.println(date.getStringData());

		Data newDate = new Data(12, 12, 2012);
		System.out.println(newDate.getStringData());

		//Testing Static ID
		System.out.println(alura.getId());
		System.out.println(leo.getId());
		System.out.println(nona.getId());

		//Using a static method
		System.out.println(Account.x());

		System.out.println(alura.getAccountStatus());
		System.out.println(leo.getAccountStatus());

	}

}


class Account {

	private static long totalUsers = 0;
	private long id;
	private double balance;
	private double creditLimit;
	private double cashOutLimit;
	private String owner;
	private boolean active = false;

	public Account(String name, double cash) {
		//This is how we can call another constructor
		this(name);
		this.balance = cash;
	}

	public Account(String name) {
		this.owner = name;
		this.balance = 0;
		//Note that a static variable does not use this.
		totalUsers++;
		this.id = totalUsers;
	}

	public Account(String name, double cash, double cLimit, double cashOutLimit) {
		//This is how we can call another constructor
		this(name, cash);
		this.creditLimit = cLimit;
		this.cashOutLimit = cashOutLimit;
		this.active = true;
	}

	public static String x() {
		return "Total Accounts in our bank: " + totalUsers;
	}

	private void error() {
		System.out.println("Error! Something went wrong...");
	}

	private void success() {
		System.out.println("Operation succeeded...");
	}

	public void cashWithdrawal(double total) {

		if (total > this.cashOutLimit || total > this.balance) {
			this.error();
			System.out.println("Cash out limit is: " + this.cashOutLimit);
			System.out.println("Your balance is: " + this.balance + "\n");
		} else {
			this.balance -= total;
			this.success();
			System.out.println("Wait for your money. Counting notes...\n");
		}

	}

	public void creditPayment(double payment) {

		if (payment > this.balance || payment > this.creditLimit) {
			this.error();
			System.out.println("Insufficient Balance or Credit Limit reached\n");
		} else {
			this.balance -= payment;
			//Taxes
			this.balance *= 0.995;
			this.success();
			System.out.println("Payment done\n");
		}

	}

	public void setFullAccount(double cLimit, double cashLimit) {
		if (this.cashOutLimit > 0 || this.creditLimit > 0) {
			this.error();
			System.out.println("Full Account already set\n");
		} else {
			this.cashOutLimit = cashLimit;
			this.creditLimit = cLimit;
			this.success();
			System.out.println("Full Account set!\n");
		}
	}

	public String getAccountStatus() {
		if (this.active) {
			return "Account " + this.owner + " is currently active";
		} else {
			return "Account " + this.owner + " is not currently active";
		}
	}

	public double getBalance() {
		return this.balance;
	}
	public String getOwner() {
		return this.owner;
	}
	public double getCashOutLimit() {
		return this.cashOutLimit;
	}
	public double getCreditLimit() {
		return this.creditLimit;
	}
	public long getId() {
		return this.id;
	}
	public boolean isActive() {
		return active;
	}

}