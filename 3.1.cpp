#include<iostream>
using namespace std;

struct Song
{
    string title;
    Song *next,*prev;
};

Song *head=NULL,*tail=NULL;

void add(string x)
{
    Song *p=new Song;
    p->title=x;
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

void del(string x)
{
    Song *p=head;

    while(p!=NULL && p->title!=x)
        p=p->next;

    if(p==NULL)
        cout<<"Song Not Found";
    else
    {
        if(p->prev) p->prev->next=p->next;
        else head=p->next;

        if(p->next) p->next->prev=p->prev;
        else tail=p->prev;

        delete p;
    }
}

void display()
{
    Song *p=head;

    while(p!=NULL)
    {
        cout<<p->title<<" -> ";
        p=p->next;
    }
}

int main()
{
    add("Song1");
    add("Song2");
    add("Song3");

    cout<<"Playlist: ";
    display();

    del("Song2");

    cout<<"\nAfter Delete: ";
    display();
}
