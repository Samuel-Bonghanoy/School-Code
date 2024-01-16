public abstract class Beverage {
  public abstract void prepare();
  public abstract void serve();
}

public class Coffee extends Beverage {
  @Override
  public void prepare() {
      System.out.println("Preparing a cup of coffee.");
  }

  @Override
  public void serve() {
      System.out.println("Serving a cup of coffee.");
  }
}

public class Tea extends Beverage {
  @Override
  public void prepare() {
      System.out.println("Brewing a cup of tea.");
  }

  @Override
  public void serve() {
      System.out.println("Serving a cup of tea.");
  }
}

public class Smoothie extends Beverage {
  @Override
  public void prepare() {
      System.out.println("Blending a delicious smoothie.");
  }

  @Override
  public void serve() {
      System.out.println("Serving a refreshing smoothie.");
  }

