# include <stdio.h>
# include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

typedef struct node node;

void insert(node **head_ref, int data)
{
    node *tmp = (node *) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = tmp;
        return;
    }
    node *p = *head_ref;
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

int present(node *head, int data)
{
    node *p = head;
    while(p)
    {
        if(p->data == data)
            return 1;
        p = p->next;
    }
    return 0;
}

node * Union(node **HRA, node **HRB)
{
    node *head = NULL;
    node *a = *HRA, *b = *HRB;
    while(a)
    {
        insert(&head, a->data);
        a = a->next;
    }
    a = *HRA;
    while(b != NULL)
    {
        if(!present(head, b->data))
            insert(&head, b->data);
        b = b->next;
    }
    return head;
}

node * Intersection(node **HRA, node **HRB)
{
    node *head = NULL, *a = *HRA, *b = *HRB;
    while(a)
    {
        if(present(b, a->data))
            insert(&head, a->data);
        a = a->next;
    }
    return head;
}

int main()
{
    int data, i;
    node *headA = NULL, *headB = NULL;

    printf("\n Enter the values to be added in the linked list A (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&headA, data);
    }

    printf("\n Enter the values to be added in the linked list B (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&headB, data);
    }

    system("clear");
    printf("\n The linked list A is as follows: \n");
    print_list(&headA);
    printf("\n");
    printf("\n The linked list B is as follows: \n");
    print_list(&headB);
    printf("\n\n");
    
    node * head_union = Union(&headA, &headB);
    printf("\n \n The Union of linked list A and Linked list B is : \n");
    print_list(&head_union);
        
    node *head = Intersection(&headA, &headB);
    printf("\n \n The Intersection of linked list A and Linked list B is : \n");
    print_list(&head);
    printf("\n");

    return 0;
}