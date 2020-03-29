#include <stdio.h>
#define MAX 10
struct queue
{
    int front, rear, elem[MAX];
} pq;

int empty()
{
    return pq.rear < pq.front ? 1 : 0;
}
int full()
{
    if (pq.rear == MAX - 1)
        return 1;
    return 0;
}

void insert()
{
    int x;
    printf("Enter the element: ");
    scanf("%d", &x);
    if (full())
        printf("Overflow");
    else
        pq.elem[++pq.rear] = x;
}

int removes()
{
    if (empty())
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        return pq.elem[pq.front++];
    }
}

void show()
{
    int i;
    if (empty())
        printf("Queue empty");
    else
    {
        for (i = pq.front; i <= pq.rear; i++)
            printf("%d   ", pq.elem[i]);
    }
}

int main(int argc, char const *argv[])
{
    pq.front = 0;
    pq.rear = -1;
    int ch = 1;
    while (ch != 0)
    {
        printf("1->Insert\n");
        printf("2->Remove\n");
        printf("3->Show\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("Removed element: %d\n", removes());
            break;
        case 3:
            show();
            break;
        default:
            printf("Incorrect option");
            break;
        }
    }
    return 0;
}
