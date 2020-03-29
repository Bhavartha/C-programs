#include <stdio.h>
int main()
{
    int i, key, j, n, arr[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }

    printf("Order of Sorted elements: ");
    for (i = 0; i < n; i++)
        printf(" %d", arr[i]);

    return 0;
}