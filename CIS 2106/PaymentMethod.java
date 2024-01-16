public interface PaymentMethod {
  void processPayment(double amount);
  void refund(double amount);
}

public class CreditCard implements PaymentMethod {
  @Override
  public void processPayment(double amount) {
      System.out.println("Credit card payment processed for $" + amount);
  }

  @Override
  public void refund(double amount) {
      System.out.println("Refund processed for credit card: $" + amount);
  }
}

public class PayPal implements PaymentMethod {
  @Override
  public void processPayment(double amount) {
      System.out.println("PayPal payment processed for $" + amount);
  }

  @Override
  public void refund(double amount) {
      System.out.println("Refund processed for PayPal: $" + amount);
  }
}

public class Bitcoin implements PaymentMethod {
  @Override
  public void processPayment(double amount) {
      System.out.println("Bitcoin payment processed for $" + amount);
  }

  @Override
  public void refund(double amount) {
      System.out.println("Refund processed for Bitcoin: $" + amount);
  }
}
