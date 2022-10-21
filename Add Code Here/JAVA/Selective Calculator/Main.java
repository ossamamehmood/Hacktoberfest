import java.util.Scanner;

class Main {

	public static void methA(double first, double second) {
		IntfA c1 = new Calculator();

		System.out.println("The addition of " + first + " & " + second + " is \n" + " " + first + " + " + second + " = "
				+ c1.add(first, second) + "\n");
		System.out.println("The subtraction of " + first + " & " + second + " is \n" + " " + first + " + " + second
				+ " = " + c1.sub(first, second) + "\n");
	}

	public static void methS(double first, double second) {
		IntfS c2 = new ScientificCalculator();

		System.out.println("The addition of " + first + " & " + second + " is \n" + " " + first + " + " + second + " = "
				+ c2.add(first, second) + "\n");
		System.out.println(
				"The substraction of " + first + " & " + second + " is \n" + " " + first + " - " + second + " = "
						+ c2.sub(first, second) + "\n");
		System.out.println("The exponent of " + first + " & " + second + " is \n" + " " + first + " ^ " + second + " = "
				+ c2.exp(first, second) + "\n");
	}

	public static void methR(double first, double second) {
		IntfR c3 = new ScientificCalculator();

		System.out.println("The addition of " + first + " & " + second + " is \n" + " " + first + " + " + second + " = "
				+ c3.add(first, second) + "\n");
		System.out.println(
				"The substraction of " + first + " & " + second + " is \n" + " " + first + " - " + second + " = "
						+ c3.sub(first, second) + "\n");
		System.out.println(
				"The multiplication of " + first + " & " + second + " is \n" + " " + first + " * " + second + " = "
						+ c3.mul(first, second) + "\n");
		System.out.println("The division of " + first + " & " + second + " is \n" + " " + first + " / " + second + " = "
				+ c3.div(first, second) + "\n");
		System.out.println("The modulous of " + first + " & " + second + " is \n" + " " + first + " % " + second + " = "
				+ c3.mod(first, second) + "\n");
		System.out.println("The exponent of " + first + " & " + second + " is \n" + " " + first + " ^ " + second + " = "
				+ c3.exp(first, second) + "\n");
		System.out.println("The log of " + first + " is \n" + " log" + first + " = "
				+ ((ScientificCalculator) c3).log(first) + "\n");
	}

	public static void main(String[] args) {

		System.out.println("\nPlease enter your first number:\n");

		try (Scanner a = new Scanner(System.in)) {
			double first = a.nextInt();

			System.out.println("Please enter your second number:\n");

			try (Scanner b = new Scanner(System.in)) {
				double second = b.nextInt();

				System.out.println("\nPlease enter your name:\n");
				try (Scanner sc = new Scanner(System.in)) {
					String name = sc.next();

					char first_Char = name.charAt(0);

					System.out.println("\nThe performed operation are :  \n");

					if (first_Char == 'A' || first_Char == 'a') {
						methA(first, second);
					} else if (first_Char == 'S' || first_Char == 's') {
						methS(first, second);
					} else {
						methR(first, second);
					}
				} catch (Exception e) {
					System.out.println(e);
				}
			} catch (Exception e) {
				System.out.println(e);
			}
		} catch (Exception e) {
			System.out.println(e);
		}

	}
}
