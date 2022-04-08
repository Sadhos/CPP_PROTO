#include <iostream>
using namespace std;
struct dl
{
    int data;
    dl *back;
    dl *forward;
} * start;
void create_head(int data)
{
    dl *node = new dl();
    node->data = data;
    node->forward = NULL;
    node->back = NULL;
    if(start == NULL)
    {
        start = new dl();
        start->forward = node;
    }
    else
    {
        dl * node1 = start;
        dl * prev = new dl();
        while(node1->forward!=NULL)
        {
            prev = node1;
            node1 = node1->forward;
        }
        node1->forward = node;
        node1->back = prev;
    }
}
void dis()
{
    dl *node = start;
    node = node->forward;
    while(node!=NULL)
    {
        cout<<node->data<<"->";
        node = node->forward;
    }
    cout<<"\n";
}
int main()
{
    create_head(100);
    create_head(200);

    dis();
    return 0;
}