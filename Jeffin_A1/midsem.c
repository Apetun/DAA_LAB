#include <stdio.h>

int count=0;

void merge(int arr[], int l, int m, int r) {
    int i, j;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;


    for(;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(L[i]>R[j])
               { printf("(%d,%d)",L[i],R[j]);
            count++;}
        }
    }


    for (i = 0; i < n1; i++) {
        arr[l+i] = L[i];
    }
    for (j = 0; j < n2; j++) {
        arr[m + 1 + j]=R[j];
    }

}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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

    mergeSort(arr, 0, n - 1);

    printf("\n");

    printf("Number of operations: %d\n", count);

    return 0;
}
