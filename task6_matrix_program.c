#include <stdio.h>

void add(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition:\n");
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}

void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int result[10][10] = {0};

    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
                result[i][j] += a[i][k] * b[k][j];

    printf("\nMatrix Multiplication:\n");
    for(int i=0;i<r1;i++) {
        for(int j=0;j<c2;j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10];
    int r, c;

    printf("Enter rows & columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter Matrix A:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &b[i][j]);

    add(a, b, r, c);
    multiply(a, b, r, c, c);

    return 0;
}
