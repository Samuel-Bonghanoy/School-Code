public interface ShoppingCart {
  void addItem(String item, double price);
  double calculateTotal();
}

import java.util.HashMap;
import java.util.Map;

public class GroceryCart implements ShoppingCart {
    private Map<String, Double> items = new HashMap<>();

    @Override
    public void addItem(String item, double price) {
        items.put(item, price);
    }

    @Override
    public double calculateTotal() {
        return items.values().stream().mapToDouble(Double::doubleValue).sum();
    }
}

import java.util.HashMap;
import java.util.Map;

public class ElectronicsCart implements ShoppingCart {
    private Map<String, Double> items = new HashMap<>();

    @Override
    public void addItem(String item, double price) {
        items.put(item, price);
    }

    @Override
    public double calculateTotal() {
        return items.values().stream().mapToDouble(Double::doubleValue).sum();
    }
}
