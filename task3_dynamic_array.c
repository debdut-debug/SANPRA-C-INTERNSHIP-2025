#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 2, count = 0, value;

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter numbers (-1 to stop):\n");

    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;

        if (count == size) {
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int));
            if (arr == NULL) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }

        arr[count++] = value;
    }

    printf("\nDynamic Array Elements:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
