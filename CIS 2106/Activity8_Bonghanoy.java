public class Activity8_Bonghanoy {
  public static void main(String[] args) {
    
    String originalString = "Hello, World!";
    String reversedString = reverseString(originalString);
    System.out.println("Reversed String: " + reversedString);

    char searchChar = 'l';
    int charCount = countOccurrences(originalString, searchChar);
    System.out.println("Occurrences of '" + searchChar + "': " + charCount);

    String uppercaseString = convertToUppercase(originalString);
    System.out.println("Uppercase String: " + uppercaseString);

    String lowercaseString = convertToLowercase(originalString);
    System.out.println("Lowercase String: " + lowercaseString);

    String[] substrings = splitString(originalString, ",");
    System.out.println("Substrings after splitting:");
    for (String substring : substrings) {
        System.out.println(substring);
    }

    String prefix = "Hell";
    String suffix = "rld!";
    boolean startsWithPrefix = startsWithSubstring(originalString, prefix);
    boolean endsWithSuffix = endsWithSubstring(originalString, suffix);
    System.out.println("Starts with '" + prefix + "': " + startsWithPrefix);
    System.out.println("Ends with '" + suffix + "': " + endsWithSuffix);
}


private static String reverseString(String input) {
    StringBuilder reversed = new StringBuilder(input);
    return reversed.reverse().toString();
}


private static int countOccurrences(String input, char searchChar) {
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input.charAt(i) == searchChar) {
            count++;
        }
    }
    return count;
}

private static String convertToUppercase(String input) {
    return input.toUpperCase();
}

private static String convertToLowercase(String input) {
    return input.toLowerCase();
}

private static String[] splitString(String input, String delimiter) {
    return input.split(delimiter);
}

private static boolean startsWithSubstring(String input, String prefix) {
    return input.startsWith(prefix);
}

private static boolean endsWithSubstring(String input, String suffix) {
    return input.endsWith(suffix);
}
}
