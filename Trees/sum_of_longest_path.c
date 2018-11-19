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

    printf("\n Right child of %d: ",data);
    tmp->right = create();

    return tmp;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int sum(node *ptr)
{
    if(ptr == NULL)
        return 0;
    return ptr->data + max(sum(ptr->left), sum(ptr->right));
}

int main()
{
    system("clear");
    root = create();
    int sum_of_longest_path = sum(root);
    printf("The sum of longest path is : %d\n", sum_of_longest_path);
}