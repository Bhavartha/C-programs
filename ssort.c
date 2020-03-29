#include <stdio.h>
int main()
{
    int i, min, j, n, temp, arr[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Order of Sorted elements: ");
    for (i = 0; i < n; i++)
        printf(" %d", arr[i]);

    return 0;
}