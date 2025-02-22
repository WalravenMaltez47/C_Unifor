#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

        // Move elements of arr[0..j-1], that are greater than key,
        // to one position ahead of their current position
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}