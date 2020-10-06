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
	
	void merge_list(SortedNode* head1, SortedNode* head2)
	{ 
		int val; 
		SortedNode* temp1 = head1; 
		SortedNode* temp2 = head2; 
		SortedNode* N = NULL; 			//newlist is the head of new sorted  linked list formed after merging 

		while(temp1 != NULL && temp2 != NULL)
		{ 
			if (temp1->info > temp2->info)
			{ 
				val = temp2->info; 
				temp2 = temp2->next; 
			} 
			else
			{ 
				val = temp1->info; 
				temp1 = temp1->next; 
			} 
			N = insert(val); 
		} 
		
												//if there are still some elements left in list1 
		while(temp1 != NULL)
		{ 
			N = insert(temp1->info); 
			temp1 = temp1->next; 
		} 
									//if there are still some elements left in list2 
		while(temp2 != NULL)
		{ 
			N = insert(temp2->info); 
			temp2 = temp2->next; 
		} 
	} 
	
	void menu()
	{
		int option;
		do
		{
			cout<<"\n****MENU****\n";
			cout<<"Press 1. For Inserting an element\n";
			cout<<"Press 2. For Display\n";
			cout<<"Press 3. For Exit\n";
			cout<<"Enter Option: ";
			cin>>option;
		
			switch(option)
			{
				case 1: cout<<"Enter Element: ";
						cin>>element;
						insert(element);
						break;
				
				case 2: cout<<"\nList is: ";
						traverse();
						cout<<"\n";
						break;
				
				case 3: cout<<"\nExitiing\n";
						break;
				
				default: cout<<"\nInvalid Input\n";
						 break;
			}
			
		}while(option!=3);	
	}
	
	void merge_list()
	{
		
	}
	
};

int main()
{
	
	SortedList *SL1;
	SL1.menu();
	
	SortedList *SL2;
	SL2.menu();
	
	cout<<"\nLists after Merging: ";
	Mergell = merge_list(SL1, SL2);
	
	return 0;
	
}

/*
case 5: cout<<"Enter number of nodes in List 1: ";
             cin>>n;
             for (int i=0;i<n;i++)
             {
                 cout<<"Enter the element you want to add: ";
                 cin>>element;
                 L1.insert(element);
             } 
             cout<<"Enter number of nodes in List 2 which is to be merged in to List 1: ";
             cin>>n;
             for (int i=0;i<n;i++)
             {
                 cout<<"Enter the element you want to add : ";
                 cin>>element;
                 L2.insert(element);
             }
             L1.merge(L2);
             L1.traverse();
             break;
			 
*/	
	
	
	
	
	
	
	
	
	
