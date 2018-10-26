// Reverse a singly linked list

# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void insert(node **head_ref, int data)
{
    node *p, *tmp;
    tmp = (node *) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = tmp;
        return;
    }
    p = *head_ref;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    return;
}

void print_list(node **head_ref)
{
    node *p = *head_ref;
    while(p != NULL)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
    return;
}

// Function to reverse a linked list iteratively
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverse_iteratively(node **head_ref)
{
    node *ptr, *next, *prev;
    ptr = *head_ref;
    prev = NULL;
    next = NULL;
    while(ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    *head_ref = prev;
}

// Function to reverse a linked list recursively
// Time Complexity: O(n)
// Space Complexity: O(1)
void reverse_recursively(node **head_ref)
{
    if(*head_ref == NULL)
        return;

    node *first, *rest;
    first = *head_ref;
    rest = first->next;

    if(rest == NULL)
        return;

    reverse_recursively(&rest);
    first->next->next = first;
    first->next = NULL;

    *head_ref = rest;
}

int main()
{
    int data, i;
    node *head = NULL;

    printf("\n Enter the values to be added in the linked list (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&head, data);
    }
    printf("\n The linked list at the moment is as follows: \n");
    print_list(&head);

    printf("\n Reverse the list using : \n 1. Two extra pointers \n 2. Three extra pointers \n");
    printf("Enter your choice :");
    scanf("%d", &i);
    switch(i)
    {
        case 1:
            reverse_recursively(&head);
            break;
        case 2:
            reverse_iteratively(&head);
            break;
        default:
            break;
    }

    printf("\n The reversed linked list is: \n");
    print_list(&head);
    return 0;
}