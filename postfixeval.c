#include <stdio.h>

#define max 21

float stack[max];
int tos = -1;

float pop()
{
    return stack[tos--];
}
void push(float f)
{
    stack[++tos] = f;
}
float eval(char o, float a, float b)
{
    if (o == '+')
        return a + b;
    else if (o == '-')
        return a - b;
    else if (o == '/')
        return a / b;
    else if (o == '*')
        return a * b;
}
void main()
{
    char x[max];
    int i;
    float op1, op2, val;
    printf("\nEnter expression: ");
    scanf("%s", &x);
    for (i = 0; x[i] != '\0'; i++)
    {
        printf("%c", x[i]);
        if (x[i] >= 48 && x[i] <= 57)
            push(x[i] - 48); 
        else 
        {
            op2 = pop();
            op1 = pop();
            val = eval(x[i], op1, op2);
            push(val);
        }
    }
    val = pop();
    printf("\n%f", val);
}