interface Decorating {
  void decorate();
}

interface Illuminating {
  void illuminate();
}

class ChristmasEntity {
  void greet() {
      System.out.println("Merry Christmas!");
  }
}

class ChristmasTree extends ChristmasEntity implements Decorating, Illuminating {
  void displayTreeInfo() {
      System.out.println("I am a beautiful Christmas tree.");
  }

  public void decorate() {
      System.out.println("The Christmas tree is decorated with ornaments.");
  }

  public void illuminate() {
      System.out.println("The Christmas tree is illuminated with lights.");
  }
}

public class HybridInheritanceExample {
  public static void main(String[] args) {
      ChristmasTree tree = new ChristmasTree();
      tree.greet();
      tree.displayTreeInfo();
      tree.decorate();
      tree.illuminate();
  }
}
