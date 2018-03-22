package structures;

import models.DNode;

public class DoublyLinkedList {

	private int size;
	private DNode head = null;
	private DNode tail = null;

	public DoublyLinkedList() {
		size = 0;
	}

	public void addHead(Object data) {
		if (this.size == 0) {
			DNode newNode = new DNode(data, null, null);
			this.head = newNode;
			this.tail = newNode;
		} else {
			DNode newNode = new DNode(data, this.head, null);
			this.head.setPrev(newNode);
			this.head = newNode;
		}
		this.size++;
	}

	public void addTail(Object data) {
		if (this.size == 0)
			addHead(data);
		else {
			DNode newNode = new DNode(data, null, this.tail);
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
			DNode beforeNode = (DNode) this.getNode(pos - 1);
			DNode afterNode = beforeNode.getNext();
			DNode newNode = new DNode(data, afterNode, beforeNode);
			beforeNode.setNext(newNode);
			afterNode.setPrev(newNode);
			this.size++;
		}
	}

	public void removeHead() {
		if (this.size == 0) {
			throw new IllegalArgumentException("List is Empty");
		}
		this.head = this.head.getNext();
		this.head.setPrev(null);
		this.size--;
		if (this.size == 0)
			this.tail = null;
	}

	public void removeTail() {
		if (this.size == 0) {
			throw new IllegalArgumentException("List is Empty");
		} else if (this.size == 1)
			removeHead();
		else {
			DNode beforeLast = this.tail.getPrev();
			beforeLast.setNext(null);
			this.tail = beforeLast;
			this.size--;
		}
	}

	public DNode detachHead() {
		DNode head = this.head;
		this.head = null;
		this.tail = null;
		this.size--;
		return head;
	}

	public DNode detachTail() {
		if (this.size == 0) {
			throw new IllegalArgumentException("List is Empty");
		} else if (this.size == 1) {
			return detachHead();
		} else {
			DNode beforeLast = this.tail.getPrev();
			DNode last = this.tail;
			beforeLast.setNext(null);
			this.tail = beforeLast;
			this.size--;
			return last;
		}
	}

	public void removeMiddle(int pos) {
		if (pos == 0)
			removeHead();
		else if (pos == this.size)
			removeTail();
		else {
			DNode beforeNode = (DNode) this.getNode(pos - 1);
			DNode target = beforeNode.getNext();
			DNode afterNode = target.getNext();
			beforeNode.setNext(afterNode);
			afterNode.setPrev(beforeNode);
			this.size--;
		}
	}

	public boolean checkPos(int pos) {
		return pos >= 0 && pos < this.size;
	}

	public Object getNode(int pos) {
		if (!checkPos(pos)) {
			throw new IllegalArgumentException("Invalid Position");
		}
		DNode node = head;
		for (int i = 0; i < pos; i++) {
			node = node.getNext();
		}
		return node;
	}

	public int getSize() {
		return this.size;
	}

	public boolean contains(Object obj) {
		DNode current = this.head;
		while (current != null) {
			if (current.getData().equals(obj))
				return true;
			current = current.getNext();
		}
		return false;
	}

	@Override
	public String toString() {
		if (this.size == 0)
			return "[]";

		DNode node = this.head;
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
