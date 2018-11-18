# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node
{
	char data;
	struct node *next;
} *top = NULL;

typedef struct node node;

char infix[100], postfix[100];

void push(char value)
{
	node *tmp = (node *) malloc(sizeof(node));
	tmp->data = value;
	tmp->next = top;
	top = tmp;
	return;
}

char pop()
{
	char data;
	node *tmp = top;
	data = tmp->data;
	top = tmp->next;
	free(tmp);
	return data;
}

int p(char c)
{
	switch(c)
	{
		case '^':
			return 3;
		case '%':
		case '/':
		case '*':
			return 2;
		case '+':
		case '-': 
			return 1;
		default:
			return 0;
	}
}

void postfixConversion(char infix[])
{
	int i = 0, j=0;
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
				while((next = pop()) != ')')
					postfix[j++] = next;
				break;
			case '^':
			case '%':
			case '/':
			case '*':
			case '+':
			case '-':
				while((top != NULL) && (p(symbol) <= p(top->data)))
					postfix[j++] = pop();
				push(symbol);
				break;
			default:
				postfix[j++] = symbol;
		}
	}
	while(top != NULL)
		postfix[j++] = pop();
	postfix[j] = '\0';
}
	

int main()
{
	printf("\n Enter the infix expression : \n");
	fgets(infix, 100, stdin);

	system("clear");
	printf("\n The entered infix expression is: ");
	fputs(infix, stdout);

	postfixConversion(infix);

	printf("\n The postfix expression is: ");
	// fputs(postfix, stdout);
	printf("%s", postfix);
	printf("\n");
	return 0;
}