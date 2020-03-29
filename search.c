#include <stdio.h>
#define MAX 20

int linear(int array[], int n, int key)
{
    int i;
    printf("\nLINEAR SEARCH");
    for (i = 0; i < n; i++)
        if (array[i] == key)
            return i;
    return -1;
}

int binary(int array[], int n, int key)
{
    int temp, i, j, mid, low = 0, high = n - 1;
    printf("\nBINARY SEARCH");
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
    printf("\nElements in sorted order: ");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == key)
            return mid;
        else if (array[mid] >= key)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

void main()
{
    int array[MAX];
    int n, key, i;
    printf("Enter the no. of elements (max 20): ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Enter the element to search: ");
    scanf("%d", &key);
    i = linear(array, n, key);
    if (i == -1)
        printf("\nElement not found");
    else
        printf("\nElement found at index %d", i);
    i = binary(array, n, key);
    if (i == -1)
        printf("\nElement not found");
    else
        printf("\nElement found at index %d", i);
}