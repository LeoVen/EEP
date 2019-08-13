int addInts(List<int> nums) {
  return nums.reduce((a, n) => a + n);
}

void main() {

  // int
  var a = 10;
  // float
  var b = 10.3;

  List<int> numbers = [];
  for (int i = 1; i <= 100; i++) {
    numbers.add(i);
  }
  print(addInts(numbers));
}
