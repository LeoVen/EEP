package tests;

import java.util.Stack;

import structures.MyStack;

public class StackTest {
	public static void main(String[] args) {

		MyStack myStack = new MyStack(10);
		myStack.push("First Box");
		myStack.push("Second Box");
		myStack.push("Third Box");
		System.out.println(myStack);
		System.out.println(myStack.pop());
		System.out.println(myStack.pop());
		System.out.println(myStack.pop());
		System.out.println(myStack);
		
		// Java equivalent
		Stack<String> stack = new Stack<String>();
		stack.push("Item 1");
		stack.push("Item 2");
		stack.push("Item 3");
		String pop = stack.pop();
		// Should print removed string
		System.out.println(pop);
		// Should print but not remove
		System.out.println(stack.peek());
	}
}
