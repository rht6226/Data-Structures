# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct node
{
	char data;
	struct node *next;
};

typedef struct node node;

node *top = NULL;
char string[100];

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
	if(top == NULL)
		exit(1);
	node *tmp = top;
	char data = top->data;
	top = tmp->next;
	free(tmp);
	return data;
}

void reverse(char string[], int size)
{
	int i;
	for(i = 0; i<size; i++)
		push(string[i]);
	for(i=0; i<size; i++)
		string[i] = pop();
	return;
}

int main()
{
	printf("\n Enter the string to be reversed: ");
	fgets(string, 100, stdin);
	printf("\n The original string : ");
	fputs(string, stdout);

	int size = strlen(string);

	reverse(string, size);

	printf("\n The reversed string is : ");
	fputs(string, stdout);

	printf("\n");
	return 0;
}