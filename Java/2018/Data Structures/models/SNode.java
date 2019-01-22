package models;

public class SNode {

	private Object data;
	private SNode next;
	
	public SNode(Object data, SNode next) {
		this.data = data;
		this.next = next;
	}

	public SNode getNext() {
		return this.next;
	}

	public void setNext(SNode next) {
		this.next = next;
	}

	public Object getData() {
		return this.data;
	}
	
}
