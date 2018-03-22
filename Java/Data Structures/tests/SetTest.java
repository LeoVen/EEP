package tests;

import java.util.HashSet;
import java.util.Set;

import structures.MySet;

public class SetTest {
	public static void main(String[] args) {
		
		MySet mySet = new MySet();
		mySet.add("Leonard");
		mySet.add("Hammilton");
		System.out.println(mySet);
		mySet.add("Lion");
		mySet.add("Leopard");
		System.out.println(mySet);
		mySet.add("Lion");
		System.out.println(mySet);
		mySet.add("X-ray");
		mySet.add("Banana");
		mySet.add("Banana");
		mySet.add("Banana");
		System.out.println(mySet);
		mySet.remove("Leonard");
		System.out.println(mySet);
		mySet.remove("Lion");
		System.out.println(mySet);
		mySet.remove("Lion");
		mySet.remove("Hammilton");
		mySet.remove("Lion");
		mySet.add("Lion");
		System.out.println(mySet);
		
		// Java equivalent
		Set<String> set = new HashSet<>();
		set.add("Cool");
		set.add("Murdock");
		set.add("Banana");
		set.add("Banana");
		for (Integer i = 0; i < 10; i++) {
			set.add(i.toString());
		}
		System.out.println(set);
		set.add("Monkey");
		System.out.println("Banana".hashCode());
		System.out.println("Banana".hashCode());
		
		
	}
}
