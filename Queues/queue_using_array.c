# include <stdio.h>
# include <stdlib.h>
# define max 100

int queue[max];
int front = -1, rear = -1;

int isEmpty()
{
	if (front == -1 || front == rear+1)
		return 1;
	return 0;
}

int isFull()
{
	if(rear == max-1)
		return 1;
	return 0;
}

void enqueue(int data)
{
	if(isFull())
	{
		printf("\n Overflow \n");
		return;
	}
	if(front == -1)
		front = 0;
	queue[++rear] = data;
	return;
}

int dequeue()
{
	if(isEmpty())
	{
		printf("\n Underflow \n");
		exit(1);
	}
	int data = queue[front++];
	return data;
}

void display()
{
	int i = front;
	if(isEmpty())
	{
		printf("\n The queue is empty \n");
		return;
	}
	printf("\n The queue is : \n");
	while(i<= rear)
		printf(" %d, ", queue[i++]);
	return;
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
				enqueue(data);
				break;
			case 2:
				data = dequeue();
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