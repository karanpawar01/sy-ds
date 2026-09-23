#include<iostream>
using namespace std;

struct Student
{
    int roll;
    char name[50];
    float marks;
};

// Input function
void input(Student *s, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\nRoll: ";
        cin>>s[i].roll;
        cout<<"Name: ";
        cin>>s[i].name;
        cout<<"Marks: ";
        cin>>s[i].marks;
    }
}

// Display function
void display(Student *s, int n)
{
    for(int i=0;i<n;i++)
        cout<<"\n"<<s[i].roll<<" "<<s[i].name<<" "<<s[i].marks;
}

// Search function
void search(Student *s, int n, int r)
{
    for(int i=0;i<n;i++)
    {
        if(s[i].roll==r)
        {
            cout<<"\nFound: "<<s[i].name<<" "<<s[i].marks;
            return;
        }
    }
    cout<<"\nStudent not found";
}

// Update function
void update(Student *s, int n, int r)
{
    for(int i=0;i<n;i++)
    {
        if(s[i].roll==r)
        {
            cout<<"Enter new marks: ";
            cin>>s[i].marks;
            return;
        }
    }
    cout<<"\nStudent not found";
}

int main()
{
    Student s[100];
    int n,r;

    cout<<"Enter number of students: ";
    cin>>n;

    input(s,n);
    display(s,n);

    cout<<"\n\nEnter roll to search: ";
    cin>>r;
    search(s,n,r);

    cout<<"\n\nEnter roll to update: ";
    cin>>r;
    update(s,n,r);

    cout<<"\n\nUpdated Records:";
    display(s,n);

    return 0;
}
