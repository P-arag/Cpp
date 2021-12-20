#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *arr, int len) {
    printf("[");
    for(int i=0; i < len; i++) {
        printf("%d", arr[i]);
        if(i < len-1)
            printf(", ");
    }
    printf("]\n");
}

int partition(int *arr, int low, int high) {
    // Select last element as pivot
    int pivot = arr[high];

    // Declare two counters
    int i = low - 1; // Swap counter
    int j; 

    for(j=low; j<high; j++) {
        if(arr[j] <= pivot) { // if current elem less than pivot
            // Increment i and swap
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    display(arr, sizeof(arr)/4);
    return i+1;
}

void quick_sort(int *arr, int low, int high) {
    if(high > low) {
        int partitioningIdx = partition(arr, low, high);

        // Pass the arrays left and right of the partitionIdx into quick_sort
        quick_sort(arr, low, partitioningIdx - 1);
        quick_sort(arr, partitioningIdx + 1, high);
    }
}   

int main() {
    int arr[] = {10, 7, 12, 6, 3, 2, 8};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);
    quick_sort(arr, 0, len-1);
    display(arr, len);
}
