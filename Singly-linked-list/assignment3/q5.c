# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

void insert(node **hr, int data)
{
	node *p;
	if(*hr == NULL)
	{
		p =(node *)malloc(sizeof(node));
		p->data = data;
		p->next = NULL;
		*hr = p;
		return;
	}
	p = *hr;
	while(p->next != NULL)
		p = p->next;
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	p->next = tmp;
	return;
}

node * reverse(node *head_ref)
{
	node *ptr, *next, *prev;
	ptr = head_ref;
	prev = NULL;
	next = NULL;
	while(ptr!=NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	return prev;
}

int isPalindrome(node **hr)
{
	node *tail, *p;
	p = *hr;
	tail = reverse(p);
	while(p != NULL)
	{
		if(p->data != tail->data)
			return 0;
		p = p->next;
		tail = tail->next;
	}
	return 1;
}


int main()
{
	node *head = NULL;
	int i, size, data;
	printf("\n Enter the size of the list : ");
	scanf("%d", &size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &data);
		insert(&head, data);
	}
	i = isPalindrome(&head);
	if(i)
		printf("Is Palindrome");
	else
		printf("Not a palindrome");
}