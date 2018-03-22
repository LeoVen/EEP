package structures;

import models.SNode;

public class SinglyLinkedList {

	private int size;
	private SNode head = null;
	private SNode tail = null;

	public SinglyLinkedList() {
		size = 0;
	}

	public void addHead(Object data) {
		SNode newNode = new SNode(data, this.head);
		this.head = newNode;
		if (this.size == 0) {
			this.tail = this.head;
		}
		size++;
	}

	public void addTail(Object data) {
		if (this.size == 0)
			addHead(data);
		else {
			SNode newNode = new SNode(data, null);
			this.tail.setNext(newNode);
			this.tail = newNode;
			this.size++;
		}
	}

	public void addMiddle(Object data, int pos) {
		if (pos == 0)
			addHead(data);
		else if (pos == this.size)
			addTail(data);
		else {
			SNode node = (SNode) this.getNode(pos - 1);
			SNode newNode = new SNode(data, node.getNext());
			node.setNext(newNode);
			this.size++;
		}
	}

	public void removeHead() {
		if (this.size == 0) {
			throw new IllegalArgumentException("List is empty");
		}
		this.head = this.head.getNext();
		this.size--;
		if (this.size == 0)
			this.tail = null;
	}

	public boolean checkPos(int pos) {
		return pos >= 0 && pos < this.size;
	}

	public Object getNode(int pos) {
		if (!checkPos(pos)) {
			throw new IllegalArgumentException("Invalid Position");
		}
		SNode node = this.head;
		for (int i = 0; i < pos; i++) {
			node = node.getNext();
		}
		return node;
	}

	public int getSize() {
		return this.size;
	}

	public boolean contains(Object obj) {

		return false;
	}

	@Override
	public String toString() {
		if (this.size == 0)
			return "[]";
		SNode node = this.head;
		StringBuilder builder = new StringBuilder("[");
		for (int i = 0; i < this.size; i++) {
			builder.append(node.getData());
			builder.append(", ");

			node = node.getNext();
		}
		builder.append("]");
		return builder.toString();
	}

}
