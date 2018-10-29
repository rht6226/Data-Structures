// Program to movea all even numbers before all odd numbers
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

void addAtBegining(node **head_ref, int data)
{
	node *new_node = (node *) malloc(sizeof(node));
	if(new_node == NULL)
	{
		printf("Overflow!");
		exit(1);
	}
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
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

void Remove(node **head_ref, int data)
{
    node *p, *tmp;
    if(*head_ref == NULL)
    {
        printf("Underflow");
        return;
    }
    if((*head_ref)->data == data)
        return;
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
    printf("\n %d does not exists in the given linked list. \n", data);
	return;
}

void rearrange(node **head_ref)
{
    if(*head_ref == NULL)
        return;
    int d, a[100] = {0}, i = 0;
    node **tmp = head_ref;
    node *p = *head_ref;
    while(p != NULL)
    {
        if(p->data %2 == 0)
        {
            d = p->data;
            a[i++] = d;
            Remove(tmp, d);    
        }
        p = p->next;
    }
    while(i--)
        addAtBegining(head_ref, a[i]);
    return;
}

int main()
{
    struct node *head = NULL;
    int data, i;
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
    
    printf("\n The linked list aftert the rearrangement is as follows: \n");
    rearrange(&head);
    print_list(&head);

    return 0;
}