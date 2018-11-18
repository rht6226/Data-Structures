# include <stdio.h>
# include <stdlib.h>

struct node
{
	int priority;
	int data;
	struct node *next;
}*front = NULL;

typedef struct node node;

int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}

void insert(int data, int priority)
{
	node *tmp = (node *) malloc(sizeof(tmp));
	tmp->data = data;
	tmp->priority = priority;

	if(isEmpty() || priority < front->priority)
	{
		tmp->next = front;
		front = tmp;
		return;
	}

	node *p = front;
	while(p->next != NULL && p->next->priority <= priority)
		p = p->next;
	tmp->next = p->next;
	p->next = tmp;
	return;
}

int delete()
{
	if(isEmpty())
	{
		printf("\n Underflow \n");
		exit(1);
	}
	node *tmp = front;
	int data = tmp->data;
	front = tmp->next;
	free(tmp);
	return data;
}

int peek()
{
	if(isEmpty())
	{
		printf("\n Underflow \n");
		exit(1);
	}
	return front->data;
}

void display()
{
	node *p = front;
	system("clear");
	printf("\n The queue is as follows : \n");
	printf("Item \t priority\n");
	while(p != NULL)
	{
		printf(" %5d \t %5d\n",p->data,p->priority);
		p = p->next;
	}
	printf("\n");
	return;
}

int main()
{
	system("clear");
	int choice, data, priority;
	while(1)
	{
		printf("\n 1. Insert element\n 2. Delete element\n 3. Peek\n 4. Show queue \n 5. Exit\n");
		printf(" Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf(" Enter the data to be inserted to the queue : ");
				scanf("%d", &data);
				printf(" Enter the priority of the node : ");
				scanf("%d", &priority);
				insert(data,priority);
				break;
			case 2:
				data = delete();
				printf("\n The deleted data is : %d\n", data);
				break;
			case 3:
				data = peek();
				printf("\n The data at the front of the queue is : %d\n", data);
				break;
			case 4:
				display();
				break;
			case 5: 
				exit(1);
			default:
				printf("\n Enter a valid choice \n");
		}
	}
	return 0;
}