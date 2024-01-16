class SantaClaus extends ChristmasEntity {
  void bringGifts() {
      System.out.println("Santa Claus brings gifts for everyone!");
  }
}

class Reindeer extends ChristmasEntity {
  void illuminate() {
      System.out.println("The reindeer, like Rudolph, illuminates the night sky.");
  }
}

public class HierarchicalInheritanceExample {
  public static void main(String[] args) {
      SantaClaus santa = new SantaClaus();
      Reindeer reindeer = new Reindeer();

      santa.greet();
      santa.bringGifts();

      reindeer.greet();
      reindeer.illuminate();
  }
}
