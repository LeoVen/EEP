package models;

public class DNode {

	private Object data;
	private DNode next;
	private DNode prev;

	public DNode(Object data, DNode next, DNode prev) {
		super();
		this.data = data;
		this.next = next;
		this.prev = prev;
	}

	public DNode getNext() {
		return next;
	}

	public void setNext(DNode next) {
		this.next = next;
	}

	public DNode getPrev() {
		return prev;
	}

	public void setPrev(DNode prev) {
		this.prev = prev;
	}

	public Object getData() {
		return data;
	}

}
