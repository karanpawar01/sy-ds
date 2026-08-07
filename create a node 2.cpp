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
	Node n2;
	
	n1.data=10;
	n2.data=20;
	
	n1.next=&n2;
	n2.next=NULL;
	
	cout<<n1.data<<" ";
	cout<<n2.data;
	
	return 0;
}
