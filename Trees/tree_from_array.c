# include <stdio.h>
# include <stdlib.h>
# define MAX 100

struct node
{
	struct node *left;
	int data;
	struct node *right;
} *root;

struct node * queue[MAX];
int front = -1, rear = -1;

typedef struct node node;

void enqueue(node *ptr)
{
	if(rear == MAX-1)
		return;
	if(front == -1)
		front++;
	queue[++rear] = ptr;
}

node *dequeue()
{
	if(front == rear+1 || front == -1)
	{
		printf("underflow");
		exit(1);
	}		
	node *ptr = queue[front++];
	return ptr;
}

int empty_queue()
{
	if(front == -1 || front == rear+1)
		return 1;
	return 0;
}

node *new_Node(int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	tmp->left =NULL;
	tmp->right = NULL;
	return tmp;
}

void insert_into_tree(node *root_node, int data)
{
	node *ptr = root_node;
	if(ptr == NULL)
	{
		printf("\n Empty tree");
		return;
	}
	enqueue(ptr);
	while(!empty_queue())
	{
		ptr = dequeue();

		if(ptr->left == NULL)
		{
			ptr->left = new_Node(data);
			break;
		}
		else
			enqueue(ptr->left);

		if(ptr->right == NULL)
		{
			ptr->right = new_Node(data);
			break;
		}
		else
			enqueue(ptr->right);
	}
	return;
}

node * insert(int *arr, int key, int size)
{
	if(key >= size)
		return NULL;
	node *tmp = (node *)malloc(sizeof(node));
	tmp->data = arr[key];
	tmp->left = insert(arr, 2*key+1, size);
	tmp->right = insert(arr, 2*key+2, size);
	return tmp;
}

void inorder(node *root_node)
{
    if(root_node == NULL)
        return;
    inorder(root_node->left);
    printf(" %d, ",root_node->data);
    inorder(root_node->right);
}

void preorder(node *root_node)
{
    if(root_node == NULL)
        return;
    printf(" %d, ",root_node->data);
    preorder(root_node->left);
    preorder(root_node->right);
}

void print_tree(node * root_node)
{
	system("clear");
	printf("\n The inorder traversal of tree is :");
	inorder(root_node);
	printf("\n\n The preorder traversal of the tree is :\n");
	preorder(root_node);
}

int main()
{
	int size, i, data;
	printf("Enter the size of the tree : \n");
	scanf("%d", &size);
	int *arr = (int *)malloc(size*sizeof(int));
	printf("\n Enter the data inside the array: ");
	for(i=0; i< size; i++)
		scanf("%d", &arr[i]);

	root = insert(arr, 0, size);
	print_tree(root);

	printf("\n Enter the data to be inserted (-1 for exit) : ");
	scanf("%d", &data);
	insert_into_tree(root, data);
	print_tree(root);
}
