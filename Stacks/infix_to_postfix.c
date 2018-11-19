# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define MAX 50

long int stack[MAX];
int top = -1;
char infix[MAX], postfix[MAX];

void push(long int symbol)
{
	if(top > MAX)
	{
		printf("\n Stack Overflow");
		return;
	}
	stack[++top] = symbol;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}

long int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow");
		exit(1);
	}
	return stack[top--];
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '(': 	
			return 0;
			break;
		case '+':
		case '-':   
			return 1;
			break;
		case '*':
		case '/':
		case '%':   
			return 2;
			break;
		case '^':   
			return 3;
			break;
		default:
			return 0;
	}
}

void infix_to_postfix()
{
	unsigned int i, p=0;
	char symbol, next;
	for(i=0; i<strlen(infix); i++)
	{
		symbol = infix[i];
		switch(symbol)
		{
			case '(':
				push(symbol);
				break;
			case ')':
				while((next = pop()) != '(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while(!isEmpty() && (priority(stack[top]) >= priority(symbol)))
					postfix[p++] = pop();
				push(symbol);
				break;
			default:
				postfix[p++] = symbol;
		}
	}
	while(!isEmpty())
		postfix[p++] = pop();
	postfix[p] = '\0';
}

long int eval()
{
	long int a, b, temp, result;
	int i=0;
	for(i=0; i<strlen(postfix); i++)
	{
		if(postfix[i] <= '9' && postfix[i] >= '0')
			push(postfix[i]-'0');
		else
		{
			a = pop();
			b = pop();
			switch(postfix[i])
			{
				case '+': temp = a+b; break;
				case '-': temp = b-a; break;
				case '*': temp = a*b; break;
				case '/': temp = b/a; break;
				case '%': temp = b%a; break;
				case '^': temp = pow(b,a); break;
			}
			push(temp);
		}
	}
	result = pop();
	return temp;
}

int main()
{
	printf("\n Enter the infix expression : \n");
	scanf("%s", infix);
	infix_to_postfix();
	printf("The Value of postfix expression is : \n");
	fputs(postfix,stdout);
	long int value = eval();
	printf("\n %ld \n ", value);
}