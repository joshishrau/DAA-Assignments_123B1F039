//PRN : 123B1F039 Assignment 3
//DATE : 04/08/25
import java.util.*;

class Item {
    int id; // item number
    double weight, value;

    Item(int id, double w, double v) {
        this.id = id;
        this.weight = w;
        this.value = v;
    }

    double valuePerWeight() {
        return value / weight;
    }
}

public class FractionalKnapsack {

    // Sort items by value/weight ratio in descending order
    static double fractionalKnapsack(List<Item> items, double capacity) {
        items.sort((a, b) -> Double.compare(b.valuePerWeight(), a.valuePerWeight()));

        double totalValue = 0.0;

        System.out.println("\nItems taken:");

        for (Item item : items) {
            if (capacity <= 0) break;

            if (item.weight <= capacity) {
                // Take whole item
                capacity -= item.weight;
                totalValue += item.value;

               System.out.println(" - Item " + item.id + ": " + item.weight + " kg taken, Value = " + item.value);


            } else {
                // Take fraction of the item
                double fraction = capacity / item.weight;
                double takenValue = item.value * fraction;
                double takenWeight = item.weight * fraction;

                totalValue += takenValue;
                capacity = 0;

                System.out.println(" - Item " + item.id + ": " + takenWeight + " kg (" 
                   + Math.round(fraction * 100) + "%) taken, Value = " + takenValue);

            }
        }
        return totalValue;
    }

    public static void main(String[] args) {
        List<Item> items = new ArrayList<>();
        items.add(new Item(1, 10, 60));   // weight = 10, value = 60
        items.add(new Item(2, 20, 100));  // weight = 20, value = 100
        items.add(new Item(3, 30, 120));  // weight = 30, value = 120

        double capacity = 50;

        double maxValue = fractionalKnapsack(items, capacity);

        System.out.printf("\nMaximum value we can obtain = %.2f\n", maxValue);
    }
}


