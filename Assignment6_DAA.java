//Shravani navnit Joshi
//PRN :123B1F039
//DATE : 01/09/25
import java.util.*;

class Item {
    int id;
    int weight;
    int utility;
    boolean perishable;

    Item(int id, int weight, int utility, boolean perishable) {
        this.id = id;
        this.weight = weight;
        this.utility = utility;
        this.perishable = perishable;
    }
}

public class Assignment6_DAA {

    
    public static void adjustPerishablePriority(Item[] items) {
        for (Item item : items) {
            if (item.perishable) {
               
                item.utility = (int) (item.utility * 1.2);
            }
        }
    }

    
    public static int knapsackDP(Item[] items, int W) {
        int n = items.length;
        int[][] dp = new int[n + 1][W + 1];

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (items[i - 1].weight <= w) {
                    dp[i][w] = Math.max(
                        items[i - 1].utility + dp[i - 1][w - items[i - 1].weight],
                        dp[i - 1][w]
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

      
        System.out.println("\nSelected Items for the Truck:");
        printSelectedItems(dp, items, W);

        return dp[n][W];
    }

    // Function to print which items are selected
    private static void printSelectedItems(int[][] dp, Item[] items, int W) {
        int i = items.length;
        int w = W;
        int totalWeight = 0;

        while (i > 0 && w > 0) {
            if (dp[i][w] != dp[i - 1][w]) {
                System.out.println("✅ Item " + items[i - 1].id +
                    " | Weight: " + items[i - 1].weight +
                    " | Utility: " + items[i - 1].utility +
                    " | Perishable: " + items[i - 1].perishable);
                totalWeight += items[i - 1].weight;
                w -= items[i - 1].weight;
            }
            i--;
        }

        System.out.println("Total Weight Loaded: " + totalWeight + " kg");
    }

    public static void main(String[] args) {
        
        Item[] items = {
            new Item(1, 10, 60, true),   
            new Item(2, 20, 100, false), 
            new Item(3, 30, 120, true),  
            new Item(4, 25, 90, false),  
            new Item(5, 15, 75, true)    
        };

        int truckCapacity = 50; 
        adjustPerishablePriority(items);

      
        int maxUtility = knapsackDP(items, truckCapacity);

      
        System.out.println("\nMaximum Total Utility (DP): " + maxUtility);
    }
}


