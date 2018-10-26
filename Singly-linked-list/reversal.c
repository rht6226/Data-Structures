# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

void insert(node **head_ref, int data);
void printlist(node **head_ref);
static void reverse(node **head_ref);

int main()
{
	node *head = NULL;
	int size, data, i;
	system("clear");

	printf("\n Enter the size of the linked list :");
	scanf("%d", &size);

	for(i=0; i<size; i++)
	{
		system("clear");
		printf("\n Enter the data to be added in the node: ");
		scanf("%d", &data);
		insert(&head, data);
	}

	printf("\n The entered linked list is as follows : ");
	printlist(&head);

	reverse(&head);

	printf("\n The reversed list is as follows : ");
	printlist(&head);

	return 0;
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
	new_node->next = NULL;
	ptr->next = new_node;
	return;
}

static void reverse(node **head_ref)
{
	node *ptr, *next, *prev;
	ptr = (*head_ref);
	prev = NULL;
	next = NULL;
	while(ptr!=NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	*head_ref = prev;
}