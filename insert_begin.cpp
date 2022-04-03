#include <iostream>
using namespace std;
struct node 
{
    int data;
    node *link;
}*head;
node * avail_node(void)
{
    node *n = new node();
    if(n!=0)
    {
        return n;
    }
    else
    {
        cout<<"Overflow"<<" ";
        return 0;
    }
}
node * insfirst(node * l1,int item)
{
    node* t = avail_node();
    t->data = item;
    t->link = l1;
    l1 = t;
    return l1;
}
int main()
{
    head = insfirst(head,100);
    head = insfirst(head,200);
    head = insfirst(head,300);
}