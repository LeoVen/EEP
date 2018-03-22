package tests;

import java.util.LinkedList;
import java.util.List;

import structures.DoublyLinkedList;

public class DLLTest {

	public static void main(String[] args) {
		
		DoublyLinkedList dll = new DoublyLinkedList();
		System.out.println(dll);
		dll.addHead("First Node");
		System.out.println(dll);
		dll.addHead("Second Node");
		System.out.println(dll);
		dll.addHead("Third Node");
		System.out.println(dll);
		dll.addTail("Fourth Node");
		System.out.println(dll);
		dll.addTail("Fifth Node");
		System.out.println(dll);
		dll.addMiddle("Sixth Node", 3);
		System.out.println(dll);
		dll.removeHead();
		dll.removeHead();
		System.out.println(dll);
		dll.removeTail();
		dll.removeTail();
		dll.removeTail();
		System.out.println(dll);
		dll.addTail("Second Node");
		dll.addTail("Fifth Node");
		dll.addTail("Third Node");
		System.out.println(dll);
		dll.removeMiddle(2);
		System.out.println(dll);
		System.out.println(dll.contains("Second Node"));
		
		// Java equivalent
		List<String> list = new LinkedList<>();
		list.add("Hello World");
	}
	
}
