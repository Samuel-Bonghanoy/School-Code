public class Activity2_Bonghanoy {
    private String name;
    private int age;
    private char gender;

    private static String country = "Unknown";

    public static void main(String[] args) {
        String localName = "John Doe";
        int localAge = 30;
        char localGender = 'M';

        Activity2_Bonghanoy person = new Activity2_Bonghanoy();

        person.name = localName;
        person.age = localAge;
        person.gender = localGender;

        System.out.println("Person Information:");
        System.out.println("Name: " + person.name);
        System.out.println("Age: " + person.age);
        System.out.println("Gender: " + person.gender);

     
        System.out.println("Country: " + country);
    }
}
