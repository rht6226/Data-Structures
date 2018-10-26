// Program to delete the middle node

# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void create_list(node **head_ref, int data)
{
    node *p, *tmp;
    tmp = (node *) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    if(*head_ref ==NULL)
    {
        *head_ref = tmp;
        return;
    }
    p = *head_ref;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
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


void midterm(node **head_ref, int data)
{
    int count = 0, i, n;
    node *p = *head_ref;
    while(p != NULL)
    {    p = p->next;
        count++;
    }
    p = *head_ref;
    n = count/2;
    for(i=1; i<n; i++)
        p = p->next;
    node *tmp = (node *) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = p->next;
    p->next = tmp;
    return;
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
        create_list(&head, data);
    }
    printf("\n The linked list at the moment is as follows: \n");
    print_list(&head);

    printf("\n Enter the term to be inserted at the middle: ");
    scanf("%d", &data);
    midterm(&head, data);

    printf("\n The linked list is: \n");
    print_list(&head);
    return 0;
}