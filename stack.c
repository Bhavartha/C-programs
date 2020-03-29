#include <stdio.h>
#include <conio.h>
#define MAX 100
struct stack
{
    int elem[MAX];
    int tos;
} ps;

void push()
{
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    if (ps.tos == MAX - 1)
        printf("Stack overflow");
    else
        ps.elem[++ps.tos] = x;
}

int pop()
{
    if (ps.tos == -1)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
        return ps.elem[ps.tos--];
}

void show()
{
    int i;
    for (int i = 0; i <= ps.tos; i++)
        printf("%d ", ps.elem[i]);
}
void main()
{
    ps.tos = -1;
    // push();
    // push();
    // show();
    // push();
    // show();
    // printf("\n%d\n", pop());
    show();
    printf("\n%d\n", pop());
}