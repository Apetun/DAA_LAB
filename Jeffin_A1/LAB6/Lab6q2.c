#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the partition position
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Function to perform quicksort
void quickSort(int array[], int low, int high, int *operationCount) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1, operationCount);
        quickSort(array, pi + 1, high, operationCount);

        // Increment operation count for partition operation
        (*operationCount)++;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int operationCount = 0;
    quickSort(array, 0, size - 1, &operationCount);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Number of operations: %d\n", operationCount);

    return 0;
}