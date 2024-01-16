public interface Character {
  void move();
  void attack();
  void useAbility();
}

public class Warrior implements Character {
  @Override
  public void move() {
      System.out.println("Warrior moves with strength and purpose.");
  }

  @Override
  public void attack() {
      System.out.println("Warrior attacks with a powerful strike!");
  }

  @Override
  public void useAbility() {
      System.out.println("Warrior activates shield ability.");
  }
}

public class Mage implements Character {
  @Override
  public void move() {
      System.out.println("Mage moves gracefully, casting spells.");
  }

  @Override
  public void attack() {
      System.out.println("Mage attacks with magical powers!");
  }

  @Override
  public void useAbility() {
      System.out.println("Mage casts a powerful spell.");
  }
}

public class Rogue implements Character {
  @Override
  public void move() {
      System.out.println("Rogue moves stealthily, avoiding detection.");
  }

  @Override
  public void attack() {
      System.out.println("Rogue attacks swiftly with precision.");
  }

  @Override
  public void useAbility() {
      System.out.println("Rogue activates cloak and dagger ability.");
  }
}

