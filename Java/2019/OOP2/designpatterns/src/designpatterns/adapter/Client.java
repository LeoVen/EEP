package designpatterns.adapter;

public class Client {

    public static void main(String[] args) {
        int[] numbers = new int[]{34, 2, 4, 12, 1};
        printNumbers(numbers);
        Sorter sorter = new SortListAdapter();
        int[] sortedNumbers = sorter.sort(numbers);
        printNumbers(sortedNumbers);
    }
    
    public static void printNumbers(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + "\t");
        }
        System.out.println("");
    }
}
