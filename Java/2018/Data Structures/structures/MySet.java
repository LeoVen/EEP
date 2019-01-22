package structures;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MySet {

	private ArrayList<LinkedList<String>> table = new ArrayList<>();
	
	public MySet() {
		for (int i = 0; i < 26; i++) {
			table.add(new LinkedList<String>());
		}
	}
	
	public void add(String wrd) {
		if(!contains(wrd)) {
			int index = getIndex(wrd);
			List<String> list = table.get(index);
			list.add(wrd);
		}
	}
	
	public void remove(String wrd) {
		if(contains(wrd)) {
			int index = getIndex(wrd);
			List<String> list = table.get(index);
			list.remove(wrd);
		}
	}
	
	private int getIndex(String wrd) {
		return wrd.toLowerCase().charAt(0) % 26;
	}
	
	private boolean contains(String wrd) {
		int index = getIndex(wrd);
		return table.get(index).contains(wrd);
	}
	
	@Override
	public String toString() {
		return table.toString();
	}
	
}
