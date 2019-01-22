package structures;

public class MyQueue {

	private DoublyLinkedList list = new DoublyLinkedList();
	
	public void queue(Object data) {
		list.addHead(data);
	}
	
	public void dequeue() {
		list.removeTail();
	}
	
	@Override
	public String toString() {
		return list.toString();
	}
	
}
