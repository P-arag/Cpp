#include<iostream>

using namespace std;

void swap(double &a , double &b){
    double temp;
    temp = a; 
    a = b;
    b = temp;
}

void print_arr(double arr[], int len){
    for(int i=0; i<len; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
int main() {
    double arr[] = {34, 5.5, 12, 66, 1, 9.9};
    cout << "The Unsorted Array <: ";
    int arrLen = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, arrLen);

    for(int i=0; i<arrLen-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<arrLen; j++) {
            if(arr[minIndex] > arr[j]){
                swap(arr[minIndex], arr[j]);
            }
        }
    }

    cout << "Selection Sorted Array <: ";
    print_arr(arr, arrLen);
}
