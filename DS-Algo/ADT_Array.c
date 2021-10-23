#include<stdio.h>
#include<stdlib.h>

// Custom data type myArray
typedef struct GoodArray{
    int total_size; // Total size of the array
    int used_size; // Current used size of the array
    int *base_ptr; // Point to 0th element
} GoodArray;

void create_array(GoodArray* a, int t_size, int u_size) {
    a->total_size = t_size;
    a->used_size = u_size;
    a->base_ptr = (int *) calloc(t_size, sizeof(int));
}

void display(GoodArray *a) {
    printf("[");
    for(int i=0; i< a-> used_size; i++) {
        if(i == a->used_size -1) {
            printf("%d]", a->base_ptr[i]);
        } else {
            printf("%d, ", a->base_ptr[i]);
        }
    }
}
int main() {
    GoodArray marks;
    create_array(&marks, 100, 50);
    display(&marks);
    return 0;
}

