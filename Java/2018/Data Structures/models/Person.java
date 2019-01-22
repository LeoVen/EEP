package models;

public class Person {

	private String name;
	
	public Person(String name) {
		this.name = name;
	}
	
	@Override
	public boolean equals(Object obj) {
		Person other = (Person) obj;
		return other.getName().equals(this.name);
	}
	
	@Override
	public String toString() {
		return name;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}	
}
