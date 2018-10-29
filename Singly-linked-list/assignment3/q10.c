# include <stdio.h>
# include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void insert(node **head_ref, int data)
{
    node *p, *tmp;
    tmp = (node *) malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = tmp;
        return;
    }
    p = *head_ref;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    return;
}

// FLoyd's cycle detection Algorithm
// Time complexity = O(n)
void detect_loop(node **head_ref)
{
    node *slow, *fast;
    slow = *head_ref;
    fast = *head_ref;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            {
                printf("\n\tLoop Detected\n");
                int i = 0, j=0;
                slow = *head_ref;
                node *tmp = fast;
                while(slow != tmp)
                {
                    j++;
                    slow = slow->next;
                }    
                slow = *head_ref;
                while(fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                    i++;
                }
                printf("\t The length of the loop is  %d\n\n", j+1-i);
                return;
            }
    }
    printf("\n \tLoop not found!\n");
    return;
}

int main()
{
    int data, i;
    node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);
    insert(&head, 70);

    head->next->next->next->next->next->next = head->next;
    
    detect_loop(&head);
    return 0;
}