#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
void insert()
{
    struct node *pnode, *current, *follow;
    pnode = (struct node *)malloc(sizeof(struct node));
    if (pnode == NULL)
        printf("Insufficient memory");
    else
    {
        printf("Enter data to be inserted: ");
        scanf("%d", &pnode->data);
        pnode->left = NULL;
        pnode->right = NULL;
        if (root == NULL)
            root = pnode;
        else
        {
            current = root;
            follow = NULL;
            while (current != NULL)
            {
                follow = current;
                if (pnode->data < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (pnode->data < follow->data)
                follow->left = pnode;
            else
                follow->right = pnode;
        }
    }
}

void search()
{
    int x;
    struct node *current;
    printf("Enter data to be searched: ");
    scanf("%d", &x);
    if (root == NULL)
        printf("%d Not found\n", x);
    else
    {
        current = root;
        while (current != NULL && current->data != x)
        {
            if (x < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (current == NULL)
            printf("\nNot found");
        else
            printf("\nFound");
    }
}

void delete ()
{
    struct node *current, *follow, *sub;
    int del;
    printf("Enter the value of node to delete: ");
    scanf("%d", &del);
    current = root;
    while (current != NULL && current->data != del)
    {
        follow = current;
        if (del < current->data)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL)
    {
        printf("Cannot delete node");
        return;
    }
    if (current->left == NULL && current->right != NULL)
    {
        if (current == root)
            root = current->right;
        else if (current == follow->left)
            follow->left = current->right;
        else
            follow->right = current->right;
    }
    else if (current->right == NULL && current->left != NULL)
    {
        if (current == root)
            root = current->left;
        else if (current == follow->left)
            follow->left = current->left;
        else
            follow->right = current->left;
    }
    else if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
            root = NULL;
        else if (current == follow->left)
            follow->left = NULL;
        else
            follow->right = NULL;
    }
    else
    {
        sub = current->right;
        while (sub->left != NULL)
            sub = sub->left;
        sub->left = current->left;
        sub->right = NULL;
        if (current == root)
            root = current->right;
        else if (current == follow->left)
            follow->left = current->right;
        else
            follow->right = current->right;
    }
}

void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        printf("\n%d", p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("\n%d", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("\n%d", p->data);
    }
}

void main()
{
    int ch;
    do
    {
        printf("\n1.insert");
        printf("\n2.search");
        printf("\n3.display inorder");
        printf("\n4.display preorder");
        printf("\n5.display postorder");
        printf("\n6.delete");
        printf("\n*.stop\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            printf("\nInorder");
            inorder(root);
            break;
        case 4:
            printf("\nPreorder");
            preorder(root);
            break;
        case 5:
            printf("\nPostorder");
            postorder(root);
            break;
        case 6:
            delete ();
            break;
        default:
            ch = 7;
            break;
        }
    } while (ch != 7);
}
