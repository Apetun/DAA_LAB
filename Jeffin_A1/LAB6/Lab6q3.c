#include <stdio.h>

void merge(int arr[], int l, int m, int r, int *count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        (*count)++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        (*count)++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        (*count)++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*count)++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*count)++;
    }
}

void mergeSort(int arr[], int l, int r, int *count) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
        merge(arr, l, m, r, count);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    mergeSort(arr, 0, n - 1, &count);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of operations: %d\n", count);

    return 0;
}