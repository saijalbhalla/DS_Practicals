#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
node* eliminate_duplicate(node* head)
{
    node *temp=head;
    node *ptr=temp->next;
    while(temp->next!=NULL)
    {
    int m=0;
        if(temp->data==ptr->data)
        {
                 temp->next=ptr->next;
           delete ptr;
                m++;
            
        } 
        if(m==0)
        temp=temp->next;
        ptr=temp->next;
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = eliminate_duplicate(head);
		print(head);
	}
	return 0;
}
