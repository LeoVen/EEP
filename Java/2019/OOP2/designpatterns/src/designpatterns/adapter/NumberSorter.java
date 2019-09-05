package designpatterns.adapter;

import java.util.Collections;
import java.util.List;

//Adaptee
public class NumberSorter {

    public List<Integer> sort(List<Integer> numbers) {
        Collections.sort(numbers);
        return numbers;
    }
}
