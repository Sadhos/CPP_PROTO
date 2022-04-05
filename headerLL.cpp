#include <iostream>
using namespace std;
struct list
{
    int data;
    list *next;
};
list *start = NULL;
void insert(int data)
{
    list *node = new list();
    node->data = data;
    node->next = NULL;
    if(start == NULL)
    {
        start = new list();
        start->next = node;
    }
    else
    {
        list *newnode = start;
        while(newnode->next != NULL)
        {
            newnode = newnode->next;
        }
        newnode->next = node;
    }
}
void dis()
{
    list *node = start;
    while(node != NULL)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"\n";
}
int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);
    cout<<"\n";
    start->data = 10;
    dis();
    return 0;
}