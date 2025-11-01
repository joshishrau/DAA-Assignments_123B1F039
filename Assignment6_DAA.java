// DisasterReliefDP.java

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

    // Function to adjust utility for perishable (high-priority) items
    public static void adjustPerishablePriority(Item[] items) {
        for (Item item : items) {
            if (item.perishable) {
                // Increase utility by 20% for perishable goods
                item.utility = (int) (item.utility * 1.2);
            }
        }
    }

    // Dynamic Programming solution for 0/1 Knapsack
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

        // Print selected items
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
        // Define the items (id, weight, utility, perishable)
        Item[] items = {
            new Item(1, 10, 60, true),   // medicines
            new Item(2, 20, 100, false), // blankets
            new Item(3, 30, 120, true),  // food
            new Item(4, 25, 90, false),  // tents
            new Item(5, 15, 75, true)    // water
        };

        int truckCapacity = 50; // Maximum weight the truck can carry

        // Step 1: Adjust priorities (perishable items get more weightage)
        adjustPerishablePriority(items);

        // Step 2: Run Dynamic Programming algorithm
        int maxUtility = knapsackDP(items, truckCapacity);

        // Step 3: Show result
        System.out.println("\nMaximum Total Utility (DP): " + maxUtility);
    }
}
