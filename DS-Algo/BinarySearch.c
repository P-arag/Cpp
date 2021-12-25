#include<stdio.h>

int binary_search(int n, int *arr, int low, int high) {
    int mid = (low + high) / 2;
    if(arr[mid] == n) 
        return mid;
    else if(arr[mid] > n)
        binary_search(n, arr, low, mid-1);
    else if(arr[mid] < n)
        binary_search(n, arr, mid+1, high);
}

int main() {
    int arr[] = {2, 12, 44, 56, 78, 99, 1010, 2000};
    int idx = binary_search(1010, arr, 0, (sizeof(arr) / 4)-1);
    printf("%d\n", idx);
}

