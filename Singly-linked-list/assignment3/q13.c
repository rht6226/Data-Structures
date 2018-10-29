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

void triplets(node **A, node **B, node **C, int data)
{
    node *a, *b, *c;
    a = *A;
    while(a != NULL)
    {
        b = *B;
        c = *C;
        while(b != NULL && c != NULL)
        { 
            int sum = a->data + b->data + c->data;
            if( sum == data)
                    {
                        printf("Triplets Found : %d %d %d", a->data, b->data, c->data);
                        return;
                    }
            else if(sum < data)
                b = b->next;
            else 
                c = c->next;
        }
        a = a->next;
    }
    printf("Triplets not found");
}

int main()
{
    struct node *A= NULL, *B = NULL, *C = NULL;
    int data, i;
    printf("\n Enter the values to be added in the linked list A (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&A, data);
    }
     printf("\n Enter the values to be added in the linked list B (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&B, data);
    }
     printf("\n Enter the values to be added in the linked list C (-1000 to stop): \n");
    for(i=0; i<100; i++)
    {
        scanf("%d", &data);
        if(data == -1000)
            break;
        insert(&C, data);
    }
    
    printf("\nEnter the sum to be searched: ");
    scanf("%d", &data);

    triplets(&A, &B, &C, data);
    return 0;
}