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

int index_parser(int len, int index) {
    return (len + index) % len;
}

void set_val(BetterArray *a, int index, int value) {
    if(index+1 > a->total_size) {
        printf("List index out of range of total size, cannot set value\n");
        exit(-1);
    }
    a->used_size = (a->used_size < index+1) ? index+1 : a->used_size;
    a->base_ptr[index] = value;        
}

void insert(BetterArray *a, int index, int value) {
    if(index+1 > a->total_size) {
        printf("List index out of range of total size, cannot insert value\n");
        exit(-1);
    }
    if(index+1 < a->used_size){
        int prev = value;
        for(int i=index; i<a->used_size; i++){
            int temp;
            temp = a->base_ptr[i];
            a->base_ptr[i] = prev;
            prev = temp;
        }
    } else {
        printf("dfas\n");
        a->base_ptr[index] = value;
        a->used_size = index+1;
    }
}

void delete(BetterArray *a, int index) {
    if(index+1 > a->total_size) {
        printf("List index out of range of total size, cannot delete value\n");
        exit(-1);
    }
    for(int i=index; i< a->used_size; i++) {
        if(i+2 < a->total_size) {
        a->base_ptr[i] = a->base_ptr[i+1];
        } else {
            a->base_ptr[i] = 0;
        }
    }
    a->used_size--;
}

int get_val(BetterArray *a, int index) {
    if(index+1 > a->total_size) {
        printf("List index out of range of total size, cannot get value\n");
        exit(-1);
    }
    index = index_parser(a->used_size, index);
    return a->base_ptr[index];
}

void summary(BetterArray *a) {
    printf("Total Size <: %d\n", a->total_size);
    printf("Used Size <: %d\n", a->used_size);
    printf("%d bytes free\n", (a->total_size - a->used_size)*sizeof(int));
}

BetterArray slice(BetterArray *a, int from, int to) { 
    if(to+1 > a->total_size) {
        printf("List index out of range of total size, cannot slice\n");
        exit(-1);
    }
    int size = to - from + 1;
    BetterArray slicedArr;
    create_array(&slicedArr, size+10, size);
    for(int i=0; i < size; i++) {
        set_val(&slicedArr, i, a->base_ptr[from]);
        from++;
    }
    return slicedArr;
}

int main() {
    BetterArray marks;
    create_array(&marks, 100, 50);
    set_val(&marks, 0, 1);
    set_val(&marks, 1, 2);
    set_val(&marks, 2, 3);
    set_val(&marks, 3, 4);
    set_val(&marks, 4, 5);
    insert(&marks, 3, 65);
    insert(&marks, 56 , 66);
    printf("%d\n", get_val(&marks, -1));

    BetterArray sliced = slice(&marks, 2, 5);
    set_val(&sliced, 12, 88);
    delete(&sliced, 1); 
    display(&marks);
    display(&sliced);
    summary(&marks);
    summary(&sliced);
    return 0;
}

