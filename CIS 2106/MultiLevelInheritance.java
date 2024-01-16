class BasicChristmasTree extends SingleLevelInhertiance {
  void displayBasicInfo() {
      System.out.println("I am a basic Christmas tree.");
  }
}

class DecoratedChristmasTree extends BasicChristmasTree {
  void describeDecorations() {
      System.out.println("I am beautifully decorated with ornaments and lights.");
  }
}

public class MultiLevelInheritanceExample {
  public static void main(String[] args) {
      DecoratedChristmasTree decoratedTree = new DecoratedChristmasTree();
      decoratedTree.greet();
      decoratedTree.displayBasicInfo();
      decoratedTree.describeDecorations();
  }
}
