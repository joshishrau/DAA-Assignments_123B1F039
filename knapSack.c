#include <stdio.h>

int main() {
    int n;
    printf("Enter a number of elements: ");
    scanf("%d", &n);

    int wt[n];
    int profit[n];
   
    int w = 0;
    int p = 0;
   
    int ksize = 25;

    for (int i = 0; i < n; i++) {
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &wt[i]);
        printf("Enter profit for item %d: ", i + 1);
        scanf("%d", &profit[i]);
    }

    printf("\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, wt[i], profit[i]);
    }
   
    for(int i = 0; i < n; i++){
        w = w + wt[i];
        if(wt[i] < ksize){
            p = p + profit[i];
            ksize = ksize - wt[i];
        }
    }
   
    printf("Profit after iterating on weight is: %d",p);
}
