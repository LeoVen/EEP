package structures;

import models.DNode;

public class MyStack {

	public DoublyLinkedList pile = new DoublyLinkedList();
	private int maxHeight;

	public MyStack(int maxHeight) {
		this.maxHeight = maxHeight;
	}

	public void push(Object data) {
		if (this.pile.getSize() == this.maxHeight) {
			throw new IllegalArgumentException("Stack is full");
		}
		pile.addTail(data);
	}

	public Object pop() {
		return this.pile.detachTail();
	}

	public boolean isEmpty() {
		if (this.pile.getSize() == 0)
			return true;
		return false;
	}

	@Override
	public String toString() {
		if (this.pile.getSize() == 0)
			return "[]";

		DNode node = (DNode) this.pile.getNode(0);
		StringBuilder builder = new StringBuilder("[\tSTACK\t\t]\n");
		for (int i = 0; i < this.pile.getSize(); i++) {
			builder.append("[\t");
			builder.append(node.getData());
			builder.append("\t]\n");
			node = node.getNext();
		}
		return builder.toString();
	}

}
