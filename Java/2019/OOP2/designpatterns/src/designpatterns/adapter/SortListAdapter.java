/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package designpatterns.adapter;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

//Adapter
public class SortListAdapter implements Sorter {

    @Override
    public int[] sort(int[] numbers) {     
        List<Integer> numberList = Arrays.stream(numbers)
                .boxed()
                .collect(Collectors.toList());
        NumberSorter sorter = new NumberSorter();
        List<Integer> sortedList = sorter.sort(numberList);
        int sortedNumbers[] = sortedList.stream()
                .filter(Objects::nonNull)
                .mapToInt(Integer::intValue)
                .toArray();
        return sortedNumbers;
    }
}
