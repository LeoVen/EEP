package tests;

import java.util.ArrayList;

import models.Person;
import structures.Vector;

public class VectorTest {
	
	public static void main(String[] args) {
		
		Person p1 = new Person("Charles");
		Person p2 = new Person("Margaret");
		Person p3 = new Person("John");
		Person p4 = new Person("Clara");
				
		Vector list = new Vector();
		
		list.push(p1);
		list.push(p2);
		list.push(p3);
		
		list.add(p4, 1);
		
		System.out.println(list);
		System.out.println(list.getSize());
		System.out.println(list.contains(p1));
		
		list.remove(0);
		list.push(p1);
		System.out.println(list);
		
		for (int i = 0; i < 301; i++) {
			Person p = new Person("John" + i);
			list.push(p);
		}
		System.out.println(list);
		
		// Java Equivalent
		ArrayList<Person> javaList = new ArrayList<>();
		javaList.add(p1);
		javaList.add(p2);
		javaList.add(p3);
		javaList.add(p4);
		javaList.contains(p2);
	}
	
}
