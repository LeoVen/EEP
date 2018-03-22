package tests;

import java.util.LinkedList;
import java.util.List;

import structures.SinglyLinkedList;

public class SLLTest {

	public static void main(String[] args) {
		
		SinglyLinkedList sll = new SinglyLinkedList();
		System.out.println(sll);
		sll.addHead("First Node");
		System.out.println(sll);
		sll.addHead("Second Node");
		System.out.println(sll);
		sll.addHead("Third Node");
		System.out.println(sll);
		sll.addTail("Fourth Node");
		System.out.println(sll);
		sll.addTail("Fifth Node");
		System.out.println(sll);
		sll.addMiddle("Sixth Node", 3);
		System.out.println(sll);
		sll.removeHead();
		sll.removeHead();
		System.out.println(sll);
		
		// Java equivalent
		// Note that this is actually a doubly linked list
		List<String> list = new LinkedList<>();
		list.add("Hello World");
	}
	
}
