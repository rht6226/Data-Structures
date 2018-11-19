# include <stdio.h>
# include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root;

typedef struct node node;

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

void postorder(node *root_node)
{
    if(root_node == NULL)
        return;
    postorder(root_node->left);
    postorder(root_node->right);
    printf(" %d, ",root_node->data);
}

int main()
{
    root = create();
    system("clear");
    printf(" The Inorder Traversal of the created tree is: \n");
    inorder(root);
    printf("\n The Preorder Traversal of the created tree is: \n");
    preorder(root);
    printf("\n The Postorder Traversal of the created tree is: \n");
    postorder(root);
}