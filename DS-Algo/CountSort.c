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

int get_max(int *arr, int len) {
    int max = arr[0];
    for(int i=0; i<len; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int arr[] = {3, 1, 9, 7, 1, 2, 4};
    int len = sizeof(arr) / sizeof(int);
    display(arr, len);

    int maxElem = get_max(arr, len);
    printf("Max element <: %d\n", maxElem);
    
    maxElem++;
    int *countArr = (int *) calloc(maxElem, sizeof(int));        

    for(int i=0; i<len; i++)
        countArr[arr[i]]++;
    display(countArr, maxElem);
    
    int fill = 0; 
    for(int j=0; j<maxElem; j++) {
        while(countArr[j] != 0) {
            printf("%d ",j);
            countArr[j]--;
        }

        if(countArr[j] != 0)
            fill++;
    }
    printf("\n");
    free(countArr);
}
