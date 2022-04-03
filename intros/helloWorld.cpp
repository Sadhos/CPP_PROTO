#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
} * head;

void insertAfter(node *prev_node, int newdata)
{
    if (prev_node == NULL)
    {
        cout << "Previous node can not be null"
             << "\n";
        return;
    }
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = prev_node->next;
    prev_node->next = newnode;
}
node *getLoc(node **head_ref, int info)
{
    node *temp = (*head_ref);
    node *prev = new node();
    while (temp->data != info)
    {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}
void dis(node **head_ref)
{
    node *temp = (*head_ref);
    while (temp != NULL)
    {
        cout << temp->data << "->"
             << "";
        temp = temp->next;
    }
    cout << temp;
    cout << "\n";
}
void push(node **head_ref, int newdata)
{
    node *temp = new node();
    temp->data = newdata;
    temp->next = (*head_ref);
    (*head_ref) = temp;
}
void append(node **head_ref, int newdata)
{
    node *temp = new node();
    temp->data = newdata;
    temp->next = NULL;
    node *lst = (*head_ref);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    lst->next = temp;
}
void reverse(node **head_ref)
{
    node *curr, *prev, *nptr = new node();
    curr = *head_ref;
    prev = NULL;
    while (curr != NULL)
    {
        nptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nptr;
    }
    head = prev;
}
int main()
{
    head = NULL;
    int n;
    cin >> n;
    while (n > 0)
    {
        int a;
        cin >> a;
        push(&head, a);
        n--;
    } /*
     int x,y;
     cout<<"Enter the node with data you want to insert after:"<<" ";
     cin>>x>>y;
     insertAfter(getLoc(&head,x),y);
     */

    dis(&head);
    reverse(&head);
    dis(&head);

    return 0;
}