package com.javaprogramto.programs.numbers.fibonacii;

import java.time.Instant;

public class PrintFibonaciiSeriesRecursive {

	public static void main(String[] args) {

		long fibResult = 0;

		System.out.println("First 30 fibonacii series numbers : ");
		long startTime = Instant.now().toEpochMilli();

		for (int i = 1; i < 30; i++) {
			fibResult = fibonacii(i);
			System.out.print(fibResult + " ");
		}
		long endTime = Instant.now().toEpochMilli();

		System.out.println("\nExecution time " + (endTime - startTime) + " ms");

		System.out.println("\nFirst 50 fibonacii series numbers : ");
		startTime = Instant.now().toEpochMilli();

		for (int i = 1; i < 50; i++) {
			fibResult = fibonacii(i);
			System.out.print(fibResult + " ");
		}
		endTime = Instant.now().toEpochMilli();

		System.out.println("\nExecution time " + (endTime - startTime) + " ms");

	}

	// fibonacii recursive
	private static long fibonacii(long n) {

		if (n <= 2) {
			return 1;
		}
		long fibNumber = fibonacii(n - 1) + fibonacii(n - 2);

		return fibNumber;
	}
}
