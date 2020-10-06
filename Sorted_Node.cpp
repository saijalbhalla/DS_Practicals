/*
Anushaka Gurjar
Roll No. 19595
Implement following operations in sorted SLL
1. Insert
2. Delete
3. Search
4. Traverse
*/


#include<bits/stdc++.h>
using namespace std;

class SortedNode
{
	public:
	int info;
	SortedNode*next;
	
	SortedNode()
	{
		info = 0;
		next = NULL;
	}
	
	SortedNode(int element)
	{
		info = element;
		next = NULL;
	}
};


class SortedList
{
	public:
	SortedNode *head; 
	SortedNode *tail;
	
	
	SortedList()
	{
		head = NULL;	 // 0
		tail = NULL;	 // 0
	}
	
	void insert(int element)
	{
		SortedNode *N = new SortedNode(element);
		
		if(head==NULL)					//List has Zero element
		{
			head = N;
			tail = N;
		}
		
		else if(head==tail)				//List has 1 element
		{
			if(head->info > N->info)
			{
				N->next = head;
				head = N;
			}
			
			else
			{
				tail->next = N;
				tail=N;
				
			}
		}
		
		else							//More than 2 elements
        {
            SortedNode *temp = head;
            while(temp->info < tail->info)
            {
            	if(N->info < head->info)
            	{
            		N->next=head;
            		head=N;
				}
				
				else if((N->info > temp->info) && (N->info < temp->next->info))
				{
					N->next=temp->next;
					temp->next=N;
				}
				
				else
					temp=temp->next;
			}
			
			if(N->info > tail->info)
			{
				tail->next = N;
				tail=N;	
			}
        }
	}
	
	void traverse()
	{
		SortedNode *temp;
		temp =  head;
		while(temp != NULL)
		{
			cout<<temp -> info <<"--> ";
			temp = temp->next;
		}
	}
	
	bool search(int element)
	{
		SortedNode *temp = head;
		while(temp!=NULL)
		{
			if(temp->info==element)
			{
				return true;
			}
			temp = temp->next;
			
		}	
		return false;
	}
	
	void del(int element)
	{
		SortedNode *curt = head;
		
		if(curt->info==element)
		{
			head=head->next;
			delete(curt);
			
		}
		
		else
		{
			SortedNode *curt = head;
			SortedNode *prev = head;
			while(curt!=NULL)
			{
				prev = curt;
				curt = curt->next;
				if(curt->info==element)
				{
					prev->next=curt->next;
					delete(curt);
					break;
				}	
			}	
		}	
	}
	
	void main_menu()
	{
		int option,element;
		do
		{
			cout<<"\n\n\t*****MENU*****\n";
			cout<<"Press 1: For Insertion of Elements\n";
			cout<<"Press 2: For Searching the Element\n";
			cout<<"Press 3: For Display\n";
			cout<<"Press 4: For Delete\n";
			cout<<"Press 5: For Exit\n";
			cout<<"Enter Choice: ";
			cin>>option;
			
			switch(option)
			{
				case 1: cout<<"Enter Element: ";
						cin>>element;
						insert(element);
						break;
				
				case 2: cout<<"Enter Element: ";
						cin>>element;
						if(search(element)==1)
						{
							cout<<"Element is Present in List\n";
						}
						else
							cout<<"Element is not present in the List\n";
						break;
				
				case 3: cout<<"\nList is: ";
						traverse();
						break;
				
				case 4: cout<<"\nEnter Element: ";
						cin>>element;
						cout<<"\nList After Deletion: ";
						del(element);
						traverse();
						break;
				
				case 5: cout<<"\nExitiing\n";
						exit(0);
				
				default: cout<<"\nInvalid Input\n";
						 break;
			}
			
		}while(option!=5);
	}
	
};

int main()
{
	SortedList SL;
	SL.main_menu();
	
	return 0;
}

