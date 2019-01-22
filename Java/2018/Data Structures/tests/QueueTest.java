package tests;

import java.util.LinkedList;
import java.util.Queue;

import structures.MyQueue;

public class QueueTest {
	public static void main(String[] args) {
		
		MyQueue myQueue = new MyQueue();
		myQueue.queue("First");
		myQueue.queue("Second");
		myQueue.queue("Third");
		myQueue.queue("Fourth");
		myQueue.queue("Fifth");
		System.out.println(myQueue);
		myQueue.dequeue();
		System.out.println(myQueue);
		myQueue.dequeue();
		myQueue.queue("Sixth");
		System.out.println(myQueue);
		myQueue.dequeue();
		myQueue.queue("Seventh");
		System.out.println(myQueue);
		myQueue.dequeue();
		myQueue.queue("Eighth");
		System.out.println(myQueue);
		
		// Java equivalent
		Queue<String> queue = new LinkedList<>();
		queue.add("F1");
		queue.poll();
		queue.add("F2");
		queue.add("F3");
		queue.poll();
		System.out.println(queue.contains("F2"));
	}
}
