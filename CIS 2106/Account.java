public abstract class Account {
    protected double balance;

    public abstract void withdraw(double amount);
    public abstract void deposit(double amount);

    public double getBalance() {
        return balance;
    }
}
