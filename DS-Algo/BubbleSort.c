#include<stdio.h>

int swap(int *a, int *b) {
    int temp;
    temp= *a;
    *a = *b;
    *b = temp;
}

int display_arr(int *a, int len) {
    for(int i=0; i<len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 11, 2, 1, 6, 9, 22};
    int len = sizeof(arr) / sizeof(int);
    int passes = 10;

    display_arr(arr, len);
    
    int j = 0;
    while(j < passes) {
        for(int i = 0; i < len; i++) {
            if(i+1 != len) {
                if(arr[i] > arr[i+1]) {
                    swap(&arr[i], &arr[i+1]);
                }
            }
        }
        j++;
    }

    display_arr(arr, len);
}
