#include <stdio.h>
#include <stdlib.h>

// Structure to hold item info
typedef struct {
    int weight;
    int profit;
    double ratio;
    int index;
} Item;

// Comparison functions for qsort
int cmpProfit(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return itemB->profit - itemA->profit;  // Descending profit
}

int cmpWeight(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return itemA->weight - itemB->weight;  // Ascending weight
}

int cmpRatio(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    else if (itemB->ratio < itemA->ratio) return -1;
    else return 0;
}

// 0/1 Knapsack DP Implementation
int zeroOneKnapsack(int capacity, Item items[], int n) {
    int i, w;
    int K[n+1][capacity+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i-1].weight <= w)
                K[i][w] = (items[i-1].profit + K[i-1][w - items[i-1].weight]) > K[i-1][w] ? (items[i-1].profit + K[i-1][w - items[i-1].weight]) : K[i-1][w];
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][capacity];
}

// Fractional Knapsack Implementation
double fractionalKnapsack(int capacity, Item items[], int n) {
    double totalProfit = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter profit for item %d: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].index = i + 1;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("\nSelect algorithm:\n1. 0/1 Knapsack\n2. Fractional Knapsack\nChoice: ");
    int algoChoice;
    scanf("%d", &algoChoice);

    if (algoChoice == 1) {
        // 0/1 Knapsack
        int maxProfit = zeroOneKnapsack(capacity, items, n);
        printf("Maximum profit using 0/1 Knapsack is: %d\n", maxProfit);
    } else if (algoChoice == 2) {
        // Fractional Knapsack
        printf("\nSelect greedy approach for fractional knapsack:\n");
        printf("1. Based on weight (lowest weight first)\n");
        printf("2. Based on profit (highest profit first)\n");
        printf("3. Based on profit/weight ratio (highest ratio first)\n");
        printf("Choice: ");
        int greedyChoice;
        scanf("%d", &greedyChoice);

        // Sort items according to greedy choice
        if (greedyChoice == 1) {
            qsort(items, n, sizeof(Item), cmpWeight);
        } else if (greedyChoice == 2) {
            qsort(items, n, sizeof(Item), cmpProfit);
        } else {
            qsort(items, n, sizeof(Item), cmpRatio);
        }

        double maxProfit = fractionalKnapsack(capacity, items, n);
        printf("Maximum profit using Fractional Knapsack (greedy) is: %.2lf\n", maxProfit);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

