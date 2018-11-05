# include <stdio.h>
# include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
}

typedef struct node node;

node *front = NULL, *back = NULL;

int isEmpty()
{
	if(front == NULL)
}