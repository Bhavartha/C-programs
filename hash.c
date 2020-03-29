#include <stdio.h>
#define max 10

void main()
{
    int hashtable[max], n, arr[max], i, probe, val;
    for (i = 0; i < max; i++)
        hashtable[i] = '\0';
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
    {
        for (probe = 0; probe < max; probe++)
        {
            val = (arr[i] % max + probe) % max;
            if (hashtable[val] == '\0')
            {
                hashtable[val] = arr[i];
                break;
            }
        }
    }
    printf("\n\nHash Table: ");
    for (i = 0; i < max; i++)
        hashtable[i] == '\0' ? printf("\nIndex %d : NULL", i) : printf("\nIndex %d : %d", i, hashtable[i]);
}