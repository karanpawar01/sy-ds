#include<iostream>
using namespace std;

struct Team
{
    string name;
    Team *next;
};

Team *last=NULL;

void add(string x)
{
    Team *p=new Team;
    p->name=x;

    if(last==NULL)
    {
        last=p;
        p->next=p;
    }
    else
    {
        p->next=last->next;
        last->next=p;
        last=p;
    }
}

void display()
{
    Team *p=last->next;

    do
    {
        cout<<p->name<<" -> ";
        p=p->next;
    }
    while(p!=last->next);
}

int main()
{
    add("Team1");
    add("Team2");
    add("Team3");
    add("Team4");

    cout<<"Round Robin: ";
    display();
}