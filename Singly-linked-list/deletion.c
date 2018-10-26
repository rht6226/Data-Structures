#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

void insert(node **head_ref, int data);
void delete(node **head_ref, int data);
void printlist(node **head_ref);

int main()
{
	node *head = NULL;
	int choice, data;
	system("clear");
	//Menu based Functionality
	while(1)
	{
		printf("\n 1. Add a node \n 2. Delete a node \n 3. Print List \n 4. Clear Screen \n 5. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				system("clear");
				printf("\n Enter the data to be added in the new node : ");
				scanf("%d", &data);
				insert(&head, data);
				break;
			case 2:
				system("clear");
				printf("\n Enter the data to be deleted : ");
				scanf("%d", &data);
				delete(&head, data);
				break;
			case 3:
				printlist(&head);
				break;
			case 4:
				system("clear");
				break;
			case 5:
				system("clear");
				exit(1);
			default:
				printf("\n Wrong choice! Enter again.\n");
		}
	}
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

void delete(node **head_ref, int data)
{
	if((*head_ref) == NULL)
	{
		printf("Underflow");
		exit(1);
	}
	node *ptr, *tmp;
	if((*head_ref)->data == data)
	{
		tmp = (*head_ref);
		(*head_ref) = tmp->next;
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
	printf("\n %d does not exists in the given linked list. \n", data);
	return;
}
