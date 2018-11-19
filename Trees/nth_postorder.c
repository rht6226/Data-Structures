# include <stdio.h>
# include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root;

typedef struct node node;
int n = 0;

node *create()
{
    int data;
    printf("\n Enter the data to be inserted (-1 for NULL): ");
    scanf("%d", &data);

    if(data == -1)
        return NULL;

    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;

    printf("\n Left child of %d : ", data);
    tmp->left = create();

    printf("\n Rightr child of %d: ",data);
    tmp->right = create();

    return tmp;
}

int postorder(node *root_node, int N)
{
    if(root_node == NULL)
        return 0;
    if(n == N)
        return root_node->data;
    postorder(root_node->left,N);
    postorder(root_node->right,N);
    // printf(" %d, ",root_node->data);
    n++;
}

int main()
{
    int N;
    root = create();
    system("clear");
    printf("\n Enter the value of N : ");
    scanf("%d",&N);
    printf("\n\n The data in the Nth node is : %d", postorder(root,N));
    return 0;    
}