# include <stdio.h>
# include <stdlib.h>
# define MAX 5

int queue[MAX];
int front =-1, rear =-1;

int isEmpty()
{
	if(front == -1)
		return 1;
	return 0;
}

int isFull()
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
		return 1;
	return 0;
}

void insert(int data)
{
	if(isFull())
	{
		printf("\n Overflow\n");
		return;
	}
	if(front == -1)
		front = 0;
	if(rear == MAX-1)
		rear = -1;
	queue[++rear] = data;
	return;
}

int delete()
{
	if(isEmpty())
	{
		printf("\n Underflow \n");
		exit(1);
	}
	int data = queue[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1)
		front = 0;
	else
		front ++;
	return data;
}

int peek()
{
	if(isEmpty())
	{
		printf("\n Underflow \n");
		exit(1);
	}
	return queue[front];
}

void display()
{
	int i = front;
	printf("\n The queue is as follows : \n");
	if(front < rear)
	{
		while(i<=rear)
		{
			printf(" %d, ", queue[i]);
			i++;
		}
	}
	else
	{
		while(i < MAX)
		{
			printf(" %d, ", queue[i]);
			i++;
		}
		i =0;
		while(i<=rear)
		{
			printf(" %d, ", queue[i]);
			i++;
		}
	}
}

int main()
{
	system("clear");
	int choice, data;
	while(1)
	{
		printf("\n 1. Insert element\n 2. Delete element\n 3. Peek\n 4. Show queue \n 5. Exit\n");
		printf(" Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter the data to be inserted to the queue : ");
				scanf("%d", &data);
				insert(data);
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
}