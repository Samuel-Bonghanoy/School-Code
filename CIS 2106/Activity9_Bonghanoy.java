public class Activity9_Bonghanoy {
  public static void main(String[] args) {
    int[] nums1D = {1, 2, 3, 4, 5};
    System.out.println("Sum of elements in 1D array: " + calculateSum(nums1D));

    int[] numsMax = {51, 12, 35, 42, 50};
    System.out.println("Maximum value in 1D array: " + findMax(numsMax));

    int[][] nums2D = {{1, 10}, {99, 12}, {3, 2}, {4, 7, 51}, {5, 45, 50}};
    System.out.println("Sum of elements in 2D array: " + calculateSum(nums2D));

    int elementToFind = 7;
    boolean elementFound = findElement(nums2D, elementToFind);
    System.out.println("Element " + elementToFind + " found in 2D array: " + elementFound);
}

private static int calculateSum(int[] array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    }
    return sum;
}

private static int findMax(int[] array) {
    int max = array[0];
    for (int num : array) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

private static int calculateSum(int[][] array) {
    int sum = 0;
    for (int[] row : array) {
        for (int num : row) {
            sum += num;
        }
    }
    return sum;
}

private static boolean findElement(int[][] array, int target) {
    for (int[] row : array) {
        for (int num : row) {
            if (num == target) {
                return true;
            }
        }
    }
    return false;
}
}
