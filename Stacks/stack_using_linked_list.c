# include <stdio.h>
# include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

node *top = NULL;

void push(int data)
{
	node *tmp = (node *) malloc(sizeof(node));
	tmp->data = data;
	tmp->next = top;
	top = tmp;
	return;
}

int pop()
{
	if(top == NULL)
	{
		printf("\n Stack Underflow! \n");
		exit(1);
	}
	int data;
	node *tmp;
	tmp = top;
	data = tmp->data;
	top = tmp->next;
	free(tmp);
	return data;
}

int peek()
{
	if(top == NULL)
	{
		printf("\n Stack Underflow! \n");
		exit(1);
	}
	return top->data;
}

void print()
{
	int arr[100], i=0, j;
	node *p = top;
	while(p != NULL)
	{
		arr[i++] = p->data;
		p = p->next;
	}
	for(j = 0; j<i; j++)
		printf("%d\n", arr[j]);
	return;
}

int main()
{
	int choice, data;
	while(1)
	{
		printf("\n 1. Push data to stack \n 2. Pop data from the stack \n 3. Take a peek \n 4. Show data \n 5. Exit \n");
		printf(" Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) 
		{
			case 1:
				system("clear");
				printf("\n Enter the data to be pushed in the stack : ");
				scanf("%d", &data);
				push(data);
				break;

			case 2:
				system("clear");
				data = pop();
				printf("\n The popped item is %d", data);
				break;

			case 3:
				system("clear");
				data = peek();
				printf("\n The item at the top is %d", data);
				break;

			case 4:
				system("clear");
				printf("\n The stack is as follows: \n");
				print();
				break;

			case 5:
				system("clear");
				exit(1);

			default:
				printf("\n wrong choice, enter again");
		}
	}	
}