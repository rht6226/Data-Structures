# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node node;

void addAtBegining(node **head_ref, int data);
void printlist(node **head_ref);
void addAtLast(node **head_ref, int data);
void addBefore(node **head_ref, int data, int info);
void addAfter(node **head_ref, int data, int info);
void addAtPosition(node **head_ref, int data, int position);

int main()
{
	node * head = NULL;
	int data, choice, info;
	system("clear");

	while(1)
	{
		printf("\n 1. Add a node \n 2. Print List \n 3. Clear Screen \n 4. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n 1. Add a node to the begining \n 2. Add a node at last \n 3. Add a node after a given node \n 4. Add a node before a given node \n 5. Add a node at a specified position \n ");
				printf(" Enter your choice : ");
				scanf("%d", &choice);

				switch(choice)
				{
					case 1:
						system("clear");
						printf("\n Enter the value to be added in the new node :");
						scanf("%d", &data);
						addAtBegining(&head, data);
						break;
					case 2:
						system("clear");
						printf("\n Enter the value to be added in the new node :");
						scanf("%d", &data);
						addAtLast(&head, data);
						break;
					case 3:
						system("clear");
						printf("\n Enter the value after which the new node is to be added : ");
						scanf("%d", &data);
						printf("\n Enter the value to be stored in the new node : ");
						scanf("%d", &info);
						addAfter(&head, data, info);
						break;
					case 4:
						system("clear");
						printf("\n Enter the value before which the new node is to be added : ");
						scanf("%d", &data);
						printf("\n Enter the value to be stored in the new node : ");
						scanf("%d", &info);
						addBefore(&head, data, info);
						break;
					case 5:
						system("clear");
						printf("\n Enter the position at which the new node is to be added : ");
						scanf("%d", &data);
						printf("\n Enter the value to be stored in the new node : ");
						scanf("%d", &info);
						addAtPosition(&head, data, info);
						break;
				}
				break;
			
			case 2:
				printlist(&head);
				break;

			case 3:
				system("clear");
				break;

			case 4:
				system("clear");
				exit(1);

			default:
				printf("\n Wrong choice");
				system("clear");
		}
	}
	return 0;
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

void printlist(node **head_ref)
{
	system("clear");
	printf("\n The linked list at the moment is as follows: \n\n");
	node *ptr = (*head_ref);
	while(ptr != NULL)
	{
		printf(" %d ->", ptr->data);
		ptr = ptr->next;
	}
	printf("\n ");
}

void addAtLast(node **head_ref, int data)
{
	node *ptr = (*head_ref);
	if (ptr == NULL)
	{
		addAtBegining(head_ref, data);
		return;
	}
	node * new_node = (node *) malloc(sizeof(node));
	if (new_node == NULL)
	{
		printf("\n Overflow");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node;
}

void addBefore(node **head_ref, int data, int info)
{
	node *ptr, *new_node;
	ptr = (* head_ref);
	if(ptr == NULL)
	{
		printf("The list is empty");
		return;
	}
	if(data == (*head_ref)->data)
	{
		addAtBegining(head_ref, info);
		return;
	}
	while(ptr->next != NULL)
	{
		if(ptr->next->data == data)
		{
			new_node = (node *) malloc(sizeof(node));
			new_node->data = info;
			new_node->next = ptr->next;
			ptr->next = new_node;
			return;
		}
		ptr = ptr->next;
	}
	system("clear");
	printf("%d is not present in the list", data);
}

void addAfter(node **head_ref, int data, int info)
{
	node *ptr = (*head_ref);
	while(ptr != NULL)
	{
		if(ptr->data == data)
		{
			node *new_node = (node *) malloc(sizeof(node));
			if(new_node == NULL)
			{
				printf("\n Overflow");
				exit(1);
			}
			new_node->data = info;
			new_node->next = ptr->next;
			ptr->next = new_node;
			return;
		}
		ptr = ptr->next;
	}
	printf("\n The Entered value doesn't exists in the current linked list");
}

void addAtPosition(node **head_ref, int position, int info)
{
	int count = 1;
	node *ptr = (*head_ref);
	if(position == 1)
	{
		addAtBegining(head_ref, info);
		return;
	}
	while(ptr != NULL)
	{
		if(count == position-1)
		{
			node *new_node = (node *) malloc(sizeof(node));
			if(new_node == NULL)
			{
				printf("\n Overflow");
				exit(1);
			}
			new_node->data = info;
			new_node->next = ptr->next;
			ptr->next = new_node;		
			return;
		}
		ptr = ptr->next;
		count++;
	}
	printf("The given position is not available in the current linked list");
}
