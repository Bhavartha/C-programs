#include <stdio.h>
#define MAX 10

struct pqueue
{
    int elem[MAX], front, rear;
} pq;

int empty()
{
    if (pq.front > pq.rear)
        return 1;
    return 0;
}

int full()
{
    if (MAX - 1 == pq.rear)
        return 1;
    return 0;
}

void insert()
{
    int elem;
    printf("Enter the element: ");
    scanf("%d", &elem);
    if (full())
        printf("Queue Overflow");
    else
        pq.elem[++pq.rear] = elem;
}

void remove_asc()
{
    int min, min_index, i;
    if (empty())
        printf("Queue underflow");
    else
    {
        min = pq.elem[pq.front];
        min_index = pq.front;
        for (i = pq.front; i <= pq.rear; i++)
            if (pq.elem[i] < min)
            {
                min = pq.elem[i];
                min_index = i;
            }
        for (i = min_index; i < pq.rear; i++)
            pq.elem[i] = pq.elem[i + 1];
        printf("Removed element %d", min);
        pq.rear--;
    }
}

void remove_desc()
{
    int max, max_index, i;
    if (empty())
        printf("Queue underflow");
    else
    {
        max = pq.elem[pq.front];
        max_index = pq.front;
        for (i = pq.front; i <= pq.rear; i++)
            if (pq.elem[i] > max)
            {
                max = pq.elem[i];
                max_index = i;
            }
        for (i = max_index; i < pq.rear; i++)
            pq.elem[i] = pq.elem[i + 1];
        printf("Removed element %d", max);
        pq.rear--;
    }
}

void display()
{
    int i;
    if (empty())
        printf("Queue empty");
    else
    {
        printf("\nElements are: ");
        for (i = pq.front; i <= pq.rear; i++)
            printf("%d  ", pq.elem[i]);
    }
}
int main(int argc, char const *argv[])
{
    pq.front = 0;
    pq.rear = -1;
    int ch = 0;
    while (ch != 5)
    {
        printf("\n1-> Insert");
        printf("\n2-> Remove ascending");
        printf("\n3-> Remove descending");
        printf("\n4-> Display");
        printf("\n*-> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            remove_asc();
            break;
        case 3:
            remove_desc();
            break;
        case 4:
            display();
            break;
        default:
            ch = 5;
            break;
        }
    }
    return 0;
}
