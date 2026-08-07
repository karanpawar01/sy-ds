#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node*next;
};
int main()
{

    Node n1;
    n1.data=10;
    n1.next=NULL;
    cout<<n1.data;
return 0;
}
