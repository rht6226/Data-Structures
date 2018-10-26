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
    node *ptr, *tmp;
    tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    if(*head_ref == NULL)
        {
            *head_ref = tmp;
            return;
        }
    ptr = *head_ref;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = tmp;
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

void remove_node(node **head_ref, int data)
{
    if(*head_ref == NULL)
        return;
    node *p, *tmp;
    if((*head_ref)->data == data)
    {
        tmp = *head_ref;
        *head_ref = tmp->next;
        free(tmp);
        return;
    }
    p = *head_ref;
    while(p->next != NULL)
    {
        if(p->next->data == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return;
        }
        p = p->next;
    }
    return;
}

void remove_duplicates(node **head_ref)
{
    node *p = *head_ref, *q;
    int data;
    while(p!= NULL)
    {
        data = p->data;
        q = p->next;
        while(q != NULL)
        {
            if(q->data == data)
                remove_node(head_ref, data);
            q = q->next;
        }
        p = p->next;
    }
    return;
}

int main()
{
    int size, data, i;
    node *head = NULL;

    printf("\n Enter the size of the linked list: ");
    scanf("%d", &size);
    printf("\n Enter the values to be added in the linked list: \n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &data);
        create_list(&head, data);
    }
    printf("\n The linked list at the moment is as follows: \n");
    print_list(&head);

    remove_duplicates(&head);

    printf("\n The linked list after the removal pf duplicate nodes is as follows: \n");
    print_list(&head);
    printf("\n");
    return 0;
}