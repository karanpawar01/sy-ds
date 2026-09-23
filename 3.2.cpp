#include<iostream>
using namespace std;

struct Song
{
    string name;
    Song *next,*prev;
};

Song *head=NULL,*tail=NULL;

void add(string x)
{
    Song *p=new Song;
    p->name=x;
    p->next=NULL;
    p->prev=tail;

    if(head==NULL)
        head=tail=p;
    else
    {
        tail->next=p;
        tail=p;
    }
}

void forward()
{
    Song *p=head;
    while(p!=NULL)
    {
        cout<<p->name<<" ";
        p=p->next;
    }
}

void backward()
{
    Song *p=tail;
    while(p!=NULL)
    {
        cout<<p->name<<" ";
        p=p->prev;
    }
}

int main()
{
    add("Song1");
    add("Song2");
    add("Song3");

    cout<<"Forward: ";
    forward();

    cout<<"\nBackward: ";
    backward();
}