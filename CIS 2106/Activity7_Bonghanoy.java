import java.util.Scanner;

public class Activity7_Bonghanoy {
    public static void printnum(String[] args) {
        System.out.println("Even numbers from 1 to 20:");
        for (int i = 2; i <= 20; i += 2) {
            System.out.println(i);
        }
    }

    public static void printarray(String[] args) {
      int[] numbers = {1, 3, 5, 7, 9};

      System.out.println("Array elements:");
      for (int number : numbers) {
          System.out.println(number);
      }
  }
      public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number to calculate its factorial: ");
        int num = scanner.nextInt();

        int factorial = 1;
        int i = 1;

        while (i <= num) {
            factorial *= i;
            i++;
        }

        System.out.println("Factorial of " + num + " is: " + factorial);

        scanner.close();
    }
}