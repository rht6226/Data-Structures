# include <stdio.h>
# include <stdlib.h>

int stack[100];
int top = -1;

void push(int data)
{
	if(top == 100)
	{
		printf("\nStack Overflow!");
		return;
	}	
	stack[++top] = data;
	return;
}

int pop()
{
	int data;
	if(top == -1)
	{
		printf("\nStack Underflow!");
		exit(1);
	}
	data = stack[top--];
	return data;
}

void print()
{
	int p = top;
	if(p == -1)
	{
		printf("\n Stack Underflow");
		return;
	}
	while(p != -1)
		printf("%d \n", stack[p--]);
	return;
}

int peek()
{
	if(top == -1)
	{
		printf("\n Stack Underflow");
		exit(1);
	}
	return stack[top];
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