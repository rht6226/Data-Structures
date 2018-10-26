# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

void insert(node **hr, int data)
{
	node *p;
	if(*hr == NULL)
	{
		p =(node *)malloc(sizeof(node));
		p->data = data;
		p->next = NULL;
		*hr = p;
		return;
	}
	p = *hr;
	while(p->next != NULL)
		p = p->next;
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	p->next = tmp;
	return;
}

void printlist(node **head_ref)
{
	node *ptr = (*head_ref);
	while(ptr != NULL)
	{
		printf(" %d ->", ptr->data);
		ptr = ptr->next;
	}
	printf("\n ");
}

void remove_node(node **head_ref, int data)
{
	if(*head_ref == NULL)
		return;
	node *ptr, *tmp;
	if((*head_ref)->data == data)
	{
		tmp = *head_ref;
		*head_ref = tmp->next;
		free(tmp);
		return;
	}
	ptr = (*head_ref);
	while(ptr->next != NULL)
	{
		if(ptr->next->data == data)
		{
			tmp = ptr->next;
			ptr->next = tmp->next;
			free(tmp);
			return;
		}
		ptr = ptr->next;
	}
	return;
}

void removeDuplicates(node **head_ref)
{
	node *p = (*head_ref);
	while(p->next != NULL)
	{
		if(p->data == p->next->data)
			remove_node(head_ref, p->data);
		p = p->next;
	}
	return;
}

int main()
{
	node *head = NULL;
	int i, size, data;
	printf("\n Enter the size of the list : ");
	scanf("%d", &size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &data);
		insert(&head, data);
	}
	printf("\n Current Linked List : ");
	printlist(&head);
	removeDuplicates(&head);
	// printf("\n Enter the data to be removed : ");
	// scanf("%d", &data);
	// remove_node(&head, data);
	printf("\n The List after removal of duplicate nodes : ");
	printlist(&head);
	printf("\n");
return 0;
}