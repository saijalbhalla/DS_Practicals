#include<bits/stdc++.h>
using namespace std;

class IntDLLNode
{
	public:
	int info;
	IntDLLNode*next;
	IntDLLNode*prev;
	
	IntDLLNode()
	{
		info = 0;
		next = NULL;
		prev = NULL;
	}
	
	IntDLLNode(int element)
	{
		info = element;
		next = NULL;
		prev = NULL;
	}
	
};

class IntDLLList
{
	public:
	IntDLLNode *head; 
	IntDLLNode *tail;
	
	
	IntDLLList()
	{
		head = NULL;	 // 0
		tail = NULL;	 // 0
	}
	
	void insertatHead(int element)
	{
		IntDLLNode* N = new IntDLLNode(element);
		
		if(head==NULL)
		{
			head = N;
			tail = N;
		}
		
		else
		{
			head->prev=N;;
			N->next-head;
			head=N;	
		}	
		
	}
	
	void insertatTail(int element)
	{
		IntDLLNode*N = new IntDLLNode(element);
		
		if(head==NULL)
		{
			head = N;
			tail = N;
		}
		
		else
		{
			N->prev=tail;
			tail->next=N;
			tail=N;
		}
		
	}
	
	void traverseforward()
	{
		
		IntDLLNode *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<temp -> info <<"--> ";
			temp = temp->next;
		}
	}
	
	bool search(int element)
	{
		IntDLLNode *temp;
		temp=head;
		
		while(temp!=NULL)
		{
			if(temp->info == element)
				return true;
			temp = temp->next;
		} 
		return false;
			
	}
	
	void traversebackward()
	{
		IntDLLNode *temp=tail;
		
		while(temp!=NULL)
		{
			cout<<temp->info<<" -->";
			temp = temp->prev;
		}
	}
	
	bool Palindrome()
	{
		IntDLLNode*temp1=head;
		IntDLLNode*temp2=tail;
		
		while(temp1!=temp2)
		{
			if(temp1->info == temp2->info)
			{
				temp1=temp1->next;
				temp2=temp2->next;
			}
			
			else return false;
		}
		
		return true;
	}
	
	
};

int main()
{

	int option,n,element;
	char choice;
	
	IntDLLList DL = IntDLLList();
	
	
	while(option!=8)
	{
	cout<<"\n\n*********MENU*********\n";
	cout<<"Press 1. Inserting an element At Beginning\n";
	cout<<"Press 2. Inserting an element At End\n";
	cout<<"Press 3. For Traversing/Display of elements FORWARD\n";
	cout<<"Press 4. For Traversing/Display of elements BACKWARD\n";
	cout<<"Press 5. For Search\n";
	cout<<"Press 6. To check whether inserted list is Palindrome or not\n";
	cout<<"Press 7. For Exit\n";

	cout<<"Enter option: ";
	cin>>option;
	
	switch(option)
	{
		case 1: cout<<"Enter an Element: ";
				cin>>element;
				DL.insertatHead(element);
				DL.traverseforward();
				break;
			
		case 2: cout<<"Enter an Element: ";
				cin>>element;
				DL.insertatTail(element);
				DL.traverseforward();
				break;
			
		case 3: DL.traverseforward();
				break;
				
		case 4: DL.traversebackward();
				break;
			
		case 5: cout<<"Element you want to find: ";
				cin>>element;
				if(DL.search(element)==1)
				{
					cout<<"\nElement is Present in List\n";
				}
				else
					cout<<"\nElement is not present in the List\n";
				break;
				
		case 6: if(DL.Palindrome() == 1)
				{
					cout<<"\nList follows Palindrome function\n\n";
				}
				else
					cout<<"\nList does not follows Palindrome function\n\n";
					break;
		
		case 7: cout<<"\n\nExiting\n";
				exit(0);
		
		
		default:cout<<"\nInvalid input\n";
	      		break;
			
	}
		
	cout<<"\n\nDo you want to continue(Y/N): ";
	cin>>choice;
			
	}while(choice=='y'|| choice=='Y');
	
		
	
	
	return 0;
}
