#include<stdio.h>
#define MAX 1000

int A[MAX], temp[MAX];

// Function to merge two halves

void merge(int left, int mid, int right) {

    int i = left;

    int j = mid + 1;

    int k = left;

    while (i <= mid && j <= right) {

        if (A[i] <= A[j])

            temp[k++] = A[i++];

        else

            temp[k++] = A[j++];

    }

    while (i <= mid)

        temp[k++] = A[i++];

    while (j <= right)

        temp[k++] = A[j++];

    for (i = left; i <= right; i++)

        A[i] = temp[i];

}

// Recursive merge sort

void mergeSort(int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSort(left, mid);

        mergeSort(mid + 1, right);

        merge(left, mid, right);

    }

}

int main() {

    int n, i;

    printf("How many elements do you want to enter? ");

    scanf("%d", &n);

    if (n > MAX) {

        printf("Maximum allowed is %d elements.\n", MAX);

        return 1;

    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)

        scanf("%d", &A[i]);

    mergeSort(0, n - 1);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)

        printf("%d ", A[i]);

    printf("\n");

    return 0;

}



