#include<iostream>
using namespace std;

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    Student s[100];
    int n;

    cout<<"Enter number of students: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Roll No: ";
        cin>>s[i].roll;

        cout<<"Enter Name: ";
        cin>>s[i].name;

        cout<<"Enter Marks: ";
        cin>>s[i].marks;
    }

    cout<<"\n--- Student Records ---\n";

    for(int i=0; i<n; i++)
    {
        cout<<"\nRoll No: "<<s[i].roll;
        cout<<"\nName: "<<s[i].name;
        cout<<"\nMarks: "<<s[i].marks<<endl;
    }

    return 0;
}
