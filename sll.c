#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

//create
void create()
{
    struct node *pnode;
    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
        printf("\nInsufficient memory");
    else
    {
        printf("\nEnter data to be inserted: ");
        scanf("%d", &pnode->data);
        pnode->next = NULL;
        if (first == NULL)
            first = last = pnode;
        else
        {
            last->next = pnode;
            last = pnode;
        }
    }
}

//insertbefore
void insertbefore()
{
    struct node *pnode, *current, *follow;
    int val;
    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
        printf("\nInsufficient memory");
    else
    {
        printf("\nEnter data to be inserted: ");
        scanf("%d", &pnode->data);
        pnode->next = NULL;
        printf("\nEnter node before which data should be inserted: ");
        scanf("%d", &val);
        current = first;
        follow = NULL;
        while (current != NULL && current->data != val)
        {
            follow = current;
            current = current->next;
        }
        if (current == NULL)
            printf("\nNode not found");
        else if (current == first)
        {
            first = pnode;
            pnode->next = current;
        }
        else
        {
            follow->next = pnode;
            pnode->next = current;
        }
    }
}

//insertafter
void insertafter()
{
    struct node *pnode, *current, *ahead;
    int val;
    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
        printf("\nInsufficient memory");
    else
    {
        printf("\nEnter data to be inserted: ");
        scanf("%d", &pnode->data);
        pnode->next = NULL;
        printf("\nEnter node after which data should be inserted: ");
        scanf("%d", &val);
        current = first;
        while (current != NULL && current->data != val)
            current = current->next;
        if (current == NULL)
            printf("\nNode not found");
        else if (current == last)
        {
            last = pnode;
            current->next = pnode;
        }
        else
        {
            ahead = current->next;
            pnode->next = ahead;
            current->next = pnode;
        }
    }
}

//traverse
void traverse()
{
    struct node *current;
    if (first == NULL)
        printf("\nLinked list is empty");
    else
    {
        current = first;
        printf("\nElements are: ");
        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->next;
        }
    }
}

//search
void search()
{
    struct node *current;
    int x;
    if (first == NULL)
        printf("\nLinked list is empty");
    else
    {
        printf("\nEnter the element to search: ");
        scanf("%d", &x);
        for (current = first; current != NULL && current->data != x; current = current->next)
            ;
        if (current == NULL)
            printf("\nNot found");
        else
            printf("\nFound");
    }
}

//destroy
void destroy()
{
    struct node *temp, *current;
    current = first;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    first = last = NULL;
}

//delete
void delete ()
{
    struct node *current, *follow;
    int x;
    printf("\nEnter value to be deleted: ");
    scanf("%d", &x);
    current = first;
    follow = NULL;
    while (current != NULL && current->data != x)
    {
        follow = current;
        current = current->next;
    }
    if (current == NULL)
        printf("\nNode not found");
    else
    {
        if (current == first && current == last)
            first = last = NULL;
        else if (current == first)
            first = current->next;
        else if (current == last)
        {
            last = follow;
            follow->next = NULL;
        }
        else
            follow->next = current->next;
        free(current);
    }
}

//main
int main(int argc, char const *argv[])
{
    int ch = 0;
    while (ch != 8)
    {
        printf("\n1-> Create");
        printf("\n2-> Insert Before");
        printf("\n3-> Insert After");
        printf("\n4-> Search");
        printf("\n5-> Delete");
        printf("\n6-> Traverse");
        printf("\n7-> Destroy");
        printf("\n*-> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insertbefore();
            break;
        case 3:
            insertafter();
            break;
        case 4:
            search();
            break;
        case 5:
            delete ();
            break;
        case 6:
            traverse();
            break;
        case 7:
            destroy();
            break;
        default:
            ch = 8;
            break;
        }
    }
    return 0;
}
