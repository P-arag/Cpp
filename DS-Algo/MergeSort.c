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

void simple_merge(int *arr1, int *arr2, int *out, int l1, int l2) {
    int i=0, j=0, k=0;
    while(i<l1 && j<l2) {
        if(arr1[i] < arr2[j]){
            out[k] = arr1[i];
            i++; 
        } else {
            out[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copies all remaining elements from both arrays to out
    while(i<l1) {
        out[k] = arr1[i];
        i++;k++;
    }
    while(j<l2) {
        out[k] = arr2[j];
        j++;k++;
    }
}

void merge(int *arr, int low, int mid, int high) {
    int i=low, j=mid+1, k=low;
    int *temp = (int *) calloc(10, 4);

    while(i<=mid && j<=high) {
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++; 
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copies all remaining elements from both arrays to out
    while(i<=mid) {
        temp[k] = arr[i];
        i++;k++;
    }
    while(j<=high) {
        temp[k] = arr[j];
        j++;k++;
    }

    // copy temp arr to main arr
    for(int t=low; t<=high; t++) {
        arr[t] = temp[t];
    }
    free(temp);
}

void merge_sort(int *arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr1[] = {1, 6, 9, 200};
    int l1 = sizeof(arr1) / 4;
    int arr2[] = {3, 7, 12, 21, 33, 110};
    int l2 = sizeof(arr2) / 4;
    int out[l1+l2];
    simple_merge(arr1, arr2, out, l1, l2);
    display(out, l1+l2);

    int arr[] = {12, 3, 45, 6, 7, 20, 2, 1, 22};
    int len = sizeof(arr) / 4;
    merge_sort(arr, 0, len-1);

    display(arr, len);
}
