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

void rounds(int n)
{
    Team *p=last->next;

    for(int i=1;i<=n;i++)
    {
        cout<<"Round "<<i<<": "<<p->name<<endl;
        p=p->next;
    }
}

int main()
{
    add("Team1");
    add("Team2");
    add("Team3");

    rounds(6);
}