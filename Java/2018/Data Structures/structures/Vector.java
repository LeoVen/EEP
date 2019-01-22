package structures;

import java.util.Arrays;

import models.Person;

public class Vector {

	private Person[] people = new Person[100];
	private int total = 0;
	
	private void grantSpace() {
		if (total == people.length) {
			Person[] newArr = new Person[people.length * 2];
			for (int i = 0; i < people.length; i++) {
				newArr[i] = people[i];
			}
			this.people = newArr;
		}
	}
	
	public void push(Person person) {
		grantSpace();
		this.people[total] = person;
		total++;
	}
	
	public boolean validPos(int pos) {
		return pos >= 0 && pos <= total;
	}
	
	public void add(Person person, int pos) {
		grantSpace();
		if (!validPos(pos)) {
			throw new IllegalArgumentException("Invalid Position");
		}
		for (int i = total -1; i >= pos; i -= 1) {
			people[i+1] = people[i];
		}
		people[pos] = person;
		total++;
	}
	
	private boolean posFilled(int pos) {
		return pos >= 0 && pos < total;
	}
	
	public Person get(int pos) {
		if (!posFilled(pos)) {
			throw new IllegalArgumentException("Invalid Position");
		}
		return people[pos];
	}
	
	public void remove(int pos) {
		for (int i = pos; i < this.total - 1; i++) {
			this.people[i] = this.people[i+1];
		}
		total--;
		this.people[total] = null;
	}
	
	public boolean contains(Person person) {
		for (int i = 0; i < total; i++) {
			if (person.equals(people[i])) return true;
		}
		return false;
	}
	
	public String toString() {
		return Arrays.toString(people);
	}
	
	public int getSize() {
		return total;
	}
	
}
