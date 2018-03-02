class Collatz {

	public static void main(String[] args) {

		int num = 32;
		int act = 0;

		while (num > 1) {

			if (num % 2 == 0) {
				num /= 2;
				act++;
			} else if (num % 3 == 0) {
				num = num * 3 + 1;
				act++;
			} else {
				System.out.println("Fatal Error");
				break;
			}

		}

		System.out.println(act);

	}

}