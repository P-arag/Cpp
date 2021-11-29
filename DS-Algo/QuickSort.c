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


void quick_sort(int *arr, int low, int high) {
    if(high <= low) {
        return;
    }
    // Start by picking an element in the middle of the list
    int middleElem = floor((high+1)/2);
    // Swap the middleElem with the lastElement
    swap(&arr[middleElem], &arr[high]);
    int pivot = arr[high];
    display(arr, high+1);
    // Declare last swapped at and is_less_than pointers
    int last_swapped=0;
    int ist =0;
    printf("Pivot is %d\n", pivot);
    // Increment ist until less than found
    while(ist < high) {
        while(arr[ist] > pivot) {ist++;}
        printf("ist %d, last_swapped %d\n", ist, last_swapped);
        // Swap ith and last_swapped
        swap(&arr[last_swapped], &arr[ist]);
        last_swapped++;
        display(arr, high+1);
    }
    printf("ist %d\n", ist);
    printf("ls %d\n", last_swapped);
    // Put left side of the array through quick_sort
    quick_sort(arr, low, last_swapped-2); 
    // Put right side of the array through quick_sort
    quick_sort(arr, last_swapped, high);
}

int main() {
    int arr[] = {10, 7, 12, 6, 3, 2, 8};
    int len = sizeof(arr) / sizeof(int);

    display(arr, len);
    quick_sort(arr, 0, len-1);
    //display(arr, len);
}
