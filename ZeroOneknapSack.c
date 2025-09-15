#include <stdio.h>

struct item {
    int wt;
    int profit;
};

// Sort by weight ascending, then profit descending if weights equal
void sortItems(struct item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].wt > items[j + 1].wt ||
               (items[j].wt == items[j + 1].wt && items[j].profit < items[j + 1].profit)) {
                struct item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// 0/1 Knapsack using Dynamic Programming
int knapsack(struct item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].wt <= w)
                dp[i][w] = (items[i - 1].profit + dp[i - 1][w - items[i - 1].wt] > dp[i - 1][w])
                            ? items[i - 1].profit + dp[i - 1][w - items[i - 1].wt]
                            : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity]; // Max profit
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct item items[n];

    printf("Enter weight and profit for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].wt, &items[i].profit);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Step 1: Sort items
    sortItems(items, n);

    printf("\nSorted Items (Weight Ascending, Profit Descending if same weight):\n");
    for (int i = 0; i < n; i++) {
        printf("WT: %d, Profit: %d\n", items[i].wt, items[i].profit);
    }

    // Step 2: Solve Knapsack
    int maxProfit = knapsack(items, n, capacity);

    printf("\nMaximum Profit: %d\n", maxProfit);

    return 0;
}

