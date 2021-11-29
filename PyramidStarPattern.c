#include<stdio.h>

int main() {
    int n=0;
    printf("Enter the number of rows <: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        int offset = n-i;
        int nStars = 2*i - 1;

        for(int o=1; o<=offset; o++) {
            printf(" ");
        }

        for(int j=1; j<= nStars; j++) {
            printf("*");
        }
        printf("\n");
    }
}
