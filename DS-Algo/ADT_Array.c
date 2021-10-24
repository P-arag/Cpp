#include<stdio.h>
#include<stdlib.h>

// Custom data type myArray
typedef struct BetterArray{
    int total_size; // Total size of the array
    int used_size; // Current used size of the array
    int *base_ptr; // Point to 0th element
} BetterArray;

void create_array(BetterArray* a, int t_size, int u_size) {
    a->total_size = t_size;
    a->used_size = u_size;
    a->base_ptr = (int *) calloc(t_size, sizeof(int));
}

void display(BetterArray *a) {
    printf("[");
    for(int i=0; i< a->used_size; i++) {
        if(i == a->used_size -1) {
            printf("%d]\n", a->base_ptr[i]);
        } else {
            printf("%d, ", a->base_ptr[i]);
        }
    }
}

void setVal(BetterArray *a, int index, int value) {
    if(index+1 > a->total_size) {
        printf("List index out of range of total size, cannot set value\n");
        return;
    }
    a->used_size = (a->used_size < index+1) ? index+1 : a->used_size;
    a->base_ptr[index] = value;        
}

int main() {
    BetterArray marks;
    create_array(&marks, 100, 50);
    setVal(&marks, 100, 32);
    display(&marks);
    return 0;
}

