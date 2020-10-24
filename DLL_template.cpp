#include<bits/stdc++.h>
using namespace std;

template <class t>
class DLLNode
{
	public:
	t info;	//template
	DLLNode*next;
	DLLNode*prev;
	
	DLLNode()
	{
		info = 0;
		next = NULL;
		prev = NULL;
	}
	
	DLLNode(t element)		//int==t
	{
		info = element;
		next = NULL;
		prev = NULL;
	}
	
};

template<class t>
class DLLList
{
	
	DLLNode<t> *head; 
	DLLNode<t> *tail;
	
	public:
	DLLList()
	{
		head = NULL;	 // 0
		tail = NULL;	 // 0
	}
	
	void insertatHead(t element)
	{
		DLLNode<t>* N = new DLLNode<t>(element);
		
		if(head==NULL)
		{
			head = N;
			tail = N;
		}
		
		else
		{
			head->prev=N;;
			N->next=head;
			head=N;	
		}	
		
	}
	
	void insertatTail(int element)
	{
		DLLNode<t>*N = new DLLNode<t>(element);
		
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
		DLLNode<t> *temp = head;
		
		while(temp!=NULL)
		{
			cout<<temp->info<<" -->";
			temp=temp->next;	
		}		
		
	}
	
	void traversebackward()
	{
		DLLNode<t> *temp=tail;
		
		while(temp!=NULL)
		{
			cout<<temp->info<<" -->";
			temp = temp->prev;
		}
	}
	
	bool search(t element)
	{
		DLLNode<t> *temp;
		temp=head;
		
		while(temp!=NULL)
		{
			if(temp->info == element)
				return true;
			temp = temp->next;
		} 
		return false;
			
	}
	
	bool Palindrome()
	{
		DLLNode<t>*temp1=head;
		DLLNode<t>*temp2=tail;
		
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
	
	void insert_after_pos(t element, int pos)
	{
		DLLNode<t>*N = new DLLNode<t>(element);
		DLLNode<t> *temp=head;
		int index = 0;
			
		if(head==NULL)
		{
			head=N;
			tail=N;
			//cout<<"List is Empty\n";
		}
		
		else if(head==tail)
		{
			tail->next=N;
			N->prev=tail;
			tail=N;		
		}
		
		else
		{
			while(1)
			{
				index++;
				if(index==pos)
					break;
				temp=temp->next;
				
				if(temp->next==NULL)
				{
					cout<<"\nEntered Position is not invalid\nElement is inserted at last of list";
					break;
				}
			}
				
			if (temp->next==NULL)
			{
				tail->next=N;
				N->prev=tail;
				tail=N;	
			}
			
			else
			{
				temp->next->prev=N;
				N->next=temp->next;
				N->prev=temp;
				temp->next=N;
			}
		}
		
	}
	
	
	void insert_before_pos(t element, int pos)
	{
		DLLNode<t>*N = new DLLNode<t>(element);
		DLLNode<t> *temp=head;
		
			
		if(head==NULL)
		{
			head=N;
			tail=N;
		//	cout<<"List is Empty\n";
		}
		
		else if(head==tail)
		{
			head->prev=N;
			N->next=head;
			head=N;	
		}
		
		else
		{
			int index = 0;
			while(1)
			{
				index++;
				if(index==pos-1)
					break;
				temp=temp->next;
				
				if(temp->next==NULL)
				{
					cout<<"\nEntered Position is not invalid\nElement is inserted at last of list";
					break;
				}
			}
				
			if (temp->next==NULL)
			{
				tail->next=N;
				N->prev=tail;
				tail=N;	
			}
			
			else
			{
				temp->next->prev=N;
				N->next=temp->next;
				N->prev=temp;
				temp->next=N;
			}
		}
		
	}
	
	void del_before_pos(int pos)
	{
		if(head==NULL)
		{
			cout<<"\nList is Empty";
		}
		else if(head==tail)
		{
			delete(head);
			head=NULL;
			tail=NULL;
		}
		else //if(head!=tail)
		{
			IntSLLNode<t>* previous  = head;
			IntSLLNode<t>* curt  = head;
			int index=0;
			while(1)
			{
				index++;
				if(index==pos-1)
					break;
				prev=curt;
				curt=curt->next;
				if(curt->next==NULL)
				{
					cout<<"\nIndex not Found";
					break;
				}	
			}
			curt->next->prev=previous;
			previous->next=curt->next;
			delete(curt);
		}
	}
	
	void del_after_pos(int pos)
	{
		if(head==NULL)
		{
			cout<<"\nList is Empty";
		}
		else if(head==tail)
		{
			delete(head);
			head=NULL;
			tail=NULL;
		}
		else //if(head!=tail)
		{
			IntSLLNode<t>* previous  = head;
			IntSLLNode<t>* curt  = head;
			int index=0;
			while(1)
			{
				index++;
				if(index==pos+1)
					break;
				prev=curt;
				curt=curt->next;
				if(curt->next==NULL)
				{
					cout<<"\nIndex not Found";
					break;
				}	
			}
			curt->next->prev=previous;
			previous->next=curt->next;
			delete(curt);
		}
		
	}
	
	void main_menu(t element)
	{
		int option, pos;
	
		do
		{
		
		cout<<"\n\n\t*******MENU*******\n";
		cout<<"Press 1. Inserting an element At Beginning\n";
		cout<<"Press 2. Inserting an element At End\n";
		cout<<"Press 3. For Traversing/Display of elements FORWARD\n";
		cout<<"Press 4. For Traversing/Display of elements BACKWARD\n";
		cout<<"Press 5. For Search\n";
		cout<<"Press 6. To check whether inserted list is Palindrome or not\n";
		cout<<"Press 7. To insert element after given position\n";
		cout<<"Press 8. To insert element before given position\n";
		cout<<"Press 9. To delete element after given Position\n";
		cout<<"Press 10. To delete element before given position\n";
		cout<<"Press 11. For Exit\n";
	
		
			cout<<"Enter option: ";
			cin>>option;
	
			switch(option)
			{
			case 1: cout<<"Enter an Element: ";
					cin>>element;
					insertatHead(element);
					traverseforward();
					break;
			
			case 2: cout<<"Enter an Element: ";
					cin>>element;
					insertatTail(element);
					traverseforward();
					break;
			
			case 3: traverseforward();
					break;
				
			case 4: traversebackward();
					break;
			
			case 5: cout<<"Element you want to find: ";
					cin>>element;
					if(search(element)==1)
					{
						cout<<"\nElement is Present in List\n";
					}
					else
						cout<<"\nElement is not present in the List\n";
						break;
				
			case 6: if(Palindrome() == 1)
					{
						cout<<"\nList follows Palindrome function\n\n";
					}
					else
						cout<<"\nList does not follows Palindrome function\n\n";
						break;
		
			case 7: cout<<"Enter Element: ";
				    cin>>element;
				    cout<<"\nEnter Position: ";
					cin>>pos;
					insert_after_pos(element,pos);
					break;
				 
			case 8: cout<<"Enter Element: ";
					cin>>element;
					cout<<"\nEnter Position: ";
					cin>>pos;
					insert_before_pos(element,pos);
					break;
			
			case 9: cout<<"Enter Position: ";
					cin>>pos;
					del_after_pos(pos);
					break;
					
			case 10: cout<<"Enter Position: ";
					cin>>pos;
					del_before_pos(pos);
					break;
			
			case 11: cout<<"\n\nExiting\n";
					exit(0);
		
		
			default:cout<<"\nInvalid input\n";
	      			break;
			
			}
			
		}while(option!=9);
	}
	
};

void menu1()
{
	cout<<"\n\n\tTYPES\n";
	cout<<"1. Int \n";
	cout<<"2. Char \n";
	cout<<"3. Float\n";
	cout<<"4. Long \n";
	cout<<"Enter Choice: ";
	
}

int main()
{

	int opt,me1,pos;
	char choice;
	
	menu1();
	cin>>me1;
	cout<<endl;
	
	if(me1 == 1)
	{
		int element;
		DLLList < int > DL;
		DL.main_menu(element);
	}
	
	else if(me1 == 2)
	{
		char element;
		DLLList <char> DL;
		DL.main_menu(element);
	}
	
	else if(me1 == 3)
	{
		float element;
		DLLList < float > DL;
		DL.main_menu(element);	
	}
	
	else if(me1 == 4)
	{
		long element;
		DLLList <long> DL;
		DL.main_menu(element);
	}
	
	else 
	{
		cout<<"\nInvalid input";	
	}
	
	return 0;
}
