class SingleLevelInhertiance {
  void greet() {
      System.out.println("Merry Christmas!");
  }
}

class ChristmasTree extends SingleLevelInhertiance {
  void displayTreeInfo() {
      System.out.println("I am a beautiful Christmas tree.");
  }
}

public class Example {
  public static void main(String[] args) {
      ChristmasTree tree = new ChristmasTree();
      tree.greet();
      tree.displayTreeInfo();
  }
}
