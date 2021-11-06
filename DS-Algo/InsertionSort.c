// Insert element in a sorted array
#include<stdio.h>
#include<stdlib.h>

void display(int *arr, int len) {
    printf("[");
    for(int i=0; i < len; i++) {
        printf("%d", arr[i]);
        if(i < len-1)
            printf(", ");
    }
    printf("]\n");
}

void insertion_sort(int *arr, int len, int n) {
    int index = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] > n) {
            index = i;
            break;
        }
    }  
    index = (index == 0) ? len : index; 

    int* a = (int *) calloc((len+1),sizeof(int));
    int nextInt = 0;
    for(int i=0; i<len+1; i++) {
        if(i < index) {
            a[i] = arr[i];
        } else {
            a[i+1] = arr[i];            
        }
    }
    
    a[index] = n;
    display(a, len+1);
    free(a);
}

int main() {
    int array[] = {3, 6, 9, 10, 117};
    int len = sizeof(array) / sizeof(int);
    display(array, len);
    insertion_sort(array, len, 118);
}
