#include <stdio.h>

void merge(int a[25], int lower, int mid, int upper)
{
    int temp[25];
    int low_p = lower, up_p = mid + 1, i = lower;
    while (low_p <= mid && up_p <= upper)
    {
        if (a[low_p] < a[up_p])
            temp[i++] = a[low_p++];
        else
            temp[i++] = a[up_p++];
    }
    while (low_p <= mid)
        temp[i++] = a[low_p++];
    while (up_p <= upper)
        temp[i++] = a[up_p++];
    for (i = lower; i <= upper; i++)
        a[i] = temp[i];
}
void mergesort(int a[25], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
int main()
{
    int i, count, number[25];

    printf("How many elements are u going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    mergesort(number, 0, count - 1);

    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);

    return 0;
}