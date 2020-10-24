#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
int data;
struct Node *next;
Node(int x){
data= x;
next=NULL;
}
};

struct Node* buildList(int size)
{
int val; cin>>val;
Node* head=new Node(val);
Node* tail=head;
for(int i=0;i<size-1;i++)
{
cin>>val;
tail->next=new Node(val);
tail=tail->next;
}
return head;
}
void printList(Node* n)
{
while(n)
{
if(n->data!=-1)
cout<<n->data<<" ";
n=n->next;
}
cout<<endl;
}
struct Node* hel(Node* h1,Node* h2)
{
while(h2!=NULL)
{
int t=h2->data;
h2=h2->next;
Node* temp=h1;
Node* p=NULL;
while(temp!=NULL && t>1)
{
p=temp; temp=temp->next;
t--;
}
if(temp==NULL)
{
break;
}
temp->data=-1;
}
return h1;
}
int main() {
int t; cin>>t;
while(t--)
{
int n,m; cin>>n;
Node* first=buildList(n);
cin>>m;
Node* second=buildList(m);
Node* res=hel(first,second);
printList(res);
}
return 0;
}
