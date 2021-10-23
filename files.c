#include<stdio.h>
int main() {
    FILE *f = fopen("/tmp/test.txt", "r");
    printf("%d\n", sizeof(f));
    // Get first character
    char c = fgetc(f);
    printf("First character <: %c\n", c);

    // Get a string
    char str[10];
    fgets(str, 5 ,f);
    printf("First 5 character string <: %s\n", str);
    
    // Close the file
    fclose(f);
    return 0;
}
