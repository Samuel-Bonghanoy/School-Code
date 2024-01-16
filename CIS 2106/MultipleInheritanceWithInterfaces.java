interface Decorating {
  void decorate();
}

interface Illuminating {
  void illuminate();
}

class ChristmasTree implements Decorating, Illuminating {
  public void decorate() {
      System.out.println("The Christmas tree is beautifully decorated.");
  }

  public void illuminate() {
      System.out.println("The Christmas tree is illuminated with lights.");
  }
}

public class MultipleInheritanceExample {
  public static void main(String[] args) {
      ChristmasTree tree = new ChristmasTree();
      tree.decorate();
      tree.illuminate();
  }
}
