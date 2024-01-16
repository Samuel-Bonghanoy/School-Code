public class CheckingAccount extends Account {
  @Override
  public void withdraw(double amount) {
      // Implement withdrawal logic for checking account
      if (balance >= amount) {
          balance -= amount;
          System.out.println("Withdrawal successful. Remaining balance: " + balance);
      } else {
          System.out.println("Insufficient funds!");
      }
  }

  @Override
  public void deposit(double amount) {
      // Implement deposit logic for checking account
      balance += amount;
      System.out.println("Deposit successful. New balance: " + balance);
  }
}
