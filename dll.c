#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
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
        pnode->prev = NULL;
        if (first == NULL)
        {
            first = last = pnode;
        }
        else
        {
            last->next = pnode;
            pnode->prev = last;
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
        pnode->prev = NULL;
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
            current->prev = pnode;
        }
        else
        {
            follow->next = pnode;
            pnode->prev = follow;
            pnode->next = current;
            current->prev = pnode;
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
        pnode->prev = NULL;
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
            pnode->prev = current;
        }
        else
        {
            ahead = current->next;
            pnode->next = ahead;
            ahead->prev = pnode;
            current->next = pnode;
            pnode->prev = current;
        }
    }
}

//traverse forward
void traverseforward()
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

//traverse backward
void traversebackward()
{
    struct node *current;
    if (first == NULL)
        printf("\nLinked list is empty");
    else
    {
        current = last;
        printf("\nElements are: ");
        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->prev;
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
        {
            first = current->next;
            first->prev = NULL;
        }
        else if (current == last)
        {
            last = follow;
            follow->next = NULL;
        }
        else
        {
            current->next->prev = follow;
            follow->next = current->next;
        }
        free(current);
    }
}

//main
int main(int argc, char const *argv[])
{
    int ch = 0;
    while (ch != 9)
    {
        printf("\n1-> Create");
        printf("\n2-> Insert Before");
        printf("\n3-> Insert After");
        printf("\n4-> Search");
        printf("\n5-> Delete");
        printf("\n6-> Traverse forward");
        printf("\n7-> Traverse backward");
        printf("\n8-> Destroy");
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
            traverseforward();
            break;
        case 7:
            traversebackward();
            break;
        case 8:
            destroy();
            break;
        default:
            ch = 9;
            break;
        }
    }
    return 0;
}
