#include<iostream>
using namespace std;

struct Employee
{
    int id;
    Employee *next;
};

Employee *head=NULL;

void insert(int x)
{
    Employee *p=new Employee;
    p->id=x;
    p->next=head;
    head=p;
}

void del(int x)
{
    Employee *p=head,*q=NULL;

    while(p!=NULL && p->id!=x)
    {
        q=p;
        p=p->next;
    }

    if(p==NULL)
        cout<<"Not Found";
    else
    {
        if(q==NULL) head=p->next;
        else q->next=p->next;
        delete p;
    }
}

void display()
{
    Employee *p=head;
    while(p!=NULL)
    {
        cout<<p->id<<" ";
        p=p->next;
    }
}

int main()
{
    insert(101);
    insert(102);
    insert(103);

    cout<<"Before deletion: ";
    display();

    del(102);

    cout<<"\nAfter deletion: ";
    display();
}
