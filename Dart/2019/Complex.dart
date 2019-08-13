class Complex {

  double real, imag;

  // Constructor
  Complex(this.real, this.imag);

  Complex operator +(Complex c) => Complex(this.real + c.real, this.imag + c.imag);
  Complex operator -(Complex c) => Complex(this.real - c.real, this.imag - c.imag);

  @override
  String toString() {
    return 'Complex(real: $real, imag: $imag)';
  }
}

Complex addInts(List<Complex> nums) {
  return nums.reduce((a, n) => a + n);
}

void main() {
  List<Complex> numbers = [];
  for (int i = 1; i <= 100; i++) {
    numbers.add(Complex(i as double, i as double));
  }
  print(addInts(numbers));
}
