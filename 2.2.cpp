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

void search(int x)
{
    Employee *p=head;

    while(p!=NULL)
    {
        if(p->id==x)
        {
            cout<<"Employee Found";
            return;
        }
        p=p->next;
    }

    cout<<"Employee Not Found";
}

int main()
{
    insert(101);
    insert(102);
    insert(103);

    int id;
    cout<<"Enter ID: ";
    cin>>id;

    search(id);
}