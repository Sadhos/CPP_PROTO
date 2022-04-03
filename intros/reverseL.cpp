#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *insert(node **head, int data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
        *head = temp;
    else
    {
        node *temp1 = *head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return *head;
}
void Print(node *p)
{
    if (p == NULL)
        return;
    Print(p->next);
    printf("%d ", p->data);
}
int main()
{
    node *head = NULL;
    head = insert(&head, 10);
    head = insert(&head, 20);
    head = insert(&head, 50);
    head = insert(&head, 67);
    Print(head);
    return 0;
}