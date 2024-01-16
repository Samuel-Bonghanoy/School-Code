public class SavingsAccount extends Account {
  @Override
  public void withdraw(double amount) {
     
      if (balance >= amount) {
          balance -= amount;
          System.out.println("Withdrawal successful. Remaining balance: " + balance);
      } else {
          System.out.println("Insufficient funds!");
      }
  }

  @Override
  public void deposit(double amount) {
      
      balance += amount;
      System.out.println("Deposit successful. New balance: " + balance);
  }
}
