#include <iostream>
using namespace std;
struct DList
{
    int data;
    DList *next;
} * head;
struct FreeList
{
    int data;
    FreeList *next;
} * AVIL;
void push(int data)
{
    DList *t = new DList();
    t->data = data;
    t->next = head;
    head = t;
}
void Print()
{
    DList *t = head;
    while (t != NULL)
    {
        cout << t->data << "->";
        t = t->next;
    }
    cout << t;
    cout << "\n";
}
void Fpop()
{
    FreeList *t = new FreeList();
    t->next = AVIL;
    AVIL = t;
}
void insert(int loc,int newdata)
{
    DList *t = head;
    DList *prev = new DList();
    while(t->data != loc)
    {
        prev = t;
        t = t->next;
    }
    if(AVIL==NULL)
    {
        cout<<"OVERFLOW"<<"\n";
        return;
    }
    else
    {
        FreeList *ft = AVIL;
        prev->next = (DList*)ft;
        AVIL = ft->next;
        ft->data = newdata;
        ft->next = (FreeList*)t;
    }  
}
int main()
{
    /*Fpop(10);*/
    int n;
    cout<<"Enter free space: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Fpop();
    }
    push(10);
    push(20);
    push(30);
    push(40);
    Print();
    insert(20,100);
    insert(20,1000); 
    insert(20,10000);
    Print();
    return 0;
}
