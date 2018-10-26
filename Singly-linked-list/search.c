# include <stdio.h>
# include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

int search(node **head_ref, int data);
void insert(node **head_ref, int data);
void printlist(node **head_ref);

int main()
{
	node * head = NULL;
	int size, data, i;
	system("clear");

	printf("\n Enter the size of the linked list: ");
	scanf("%d", &size);
	system("clear");

	for(i=0; i<size; i++)
	{
		printf("\n Enter the data to be added: ");
		scanf("%d", &data);
		insert(&head, data);
		system("clear");
	}
	
	printf("\n Enter the element to be searched : ");
	scanf("%d", &data);
	i = search(&head, data);

	if(i>=0)
	{
		printf("\n The element %d was found at the position %d in the entered linked list\n", data, i);
		return 0;
	}
	system("clear");
	printf("\n The entered element does not exists in the current linked list: \n");
	printlist(&head);
}

void printlist(node **head_ref)
{
	printf("\n The linked list at the moment is as follows: \n\n");
	node *ptr = (*head_ref);
	while(ptr != NULL)
	{
		printf(" %d ->", ptr->data);
		ptr = ptr->next;
	}
	printf("\n ");
}

void insert(node **head_ref, int data)
{	if((*head_ref) == NULL)
	{
		node *new_node = (node *) malloc(sizeof(node));
		new_node->data = data;
		new_node->next = NULL;
		(*head_ref) = new_node;
		return;
	}
	node *ptr = (*head_ref);
	while(ptr->next !=NULL)
		ptr = ptr->next;
	node *new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = ptr->next;
	ptr->next = new_node;
	return;
}

int search(node **head_ref, int data)
{
	node *ptr = (*head_ref);
	int i=0;
	while(ptr != NULL)
	{
		if(ptr->data == data)
			return i+1;
		ptr = ptr->next;
		i++;
	}
	return -2;
}
