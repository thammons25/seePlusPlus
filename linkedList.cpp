#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;



struct node
{
	int info;
	struct node *next;
} *start;


class singleList
{
public:
	node *createNode(int);
	void insertBegin();
	void insertPos();
	void insertLast();
	void deletePos();
	void sort();
	void search();
	void update();
	void reverse();
	void display();
	singleList()
	{
		start = NULL;
	}
};



int main()
{
	int choice , nodes , element , position , i;
	singleList sl;
	start = NULL;
	while(1)
	{
		cout << endl;
		cout << endl;
		cout << "Operations on singly linked list" << endl;
		cout << endl;
		cout << "1.Insert node at beginning" << endl;
		cout << "2.Insert node at last" << endl;
		cout << "3.Insert node at position" << endl;
		cout << "4.Sort link list" << endl;
		cout << "5.Delete a particular node" << endl;
		cout << "6.Update node value" << endl;
		cout << "7.Search element" << endl;
		cout << "8.Display linked list" << endl;
		cout << "9.Reverse linked list" << endl;
		cout << "10.Exit" << endl;
		cout << "Enter choice here: " ;
		cin >> choice;
		cout << endl;
		switch(choice)
		{
			case 1:
				cout << "Inserting node at beginning" << endl;
				sl.insertBegin();
				cout << endl;
				break;
			case 2:
				cout << "Inserting node at last" << endl;
				sl.insertLast();
				cout << endl;
				break;
			case 3:
				 cout << "Inserting node at given position" << endl;
				 sl.insertPos();
				 cout << endl;
				 break;
			case 4:
				cout << "Sort linked list" << endl;
				sl.sort();
				cout << endl;
				break;
			case 5:
				cout << "Delete a particular node" << endl;
				sl.deletePos();
				cout << endl;
				break;
			case 6:
				cout << "Update new node value" << endl;
				sl.update();
				cout << endl;
				break;
			case 7:
				cout << "Search element in linked list" << endl;
				sl.search();
				cout << endl;
				break;
			case 8:
				cout << "Display elements of linked list" << endl;
				sl.display();
				cout << endl;
				break;
			case 9:
				cout << "Reverse elements of linked list=" << endl;
				sl.reverse();
				cout << endl;
				break;
			case 10:
				cout << "Exiting..." << endl;
				exit(1);
				break;
			default:
				cout << "Invalid Choice" << endl;
		}
	}
}




node *singleList::createNode( int value )
{
	struct node *temp , *s;
	temp = new(struct node );
	if( temp == NULL )
	{
		cout << "Memory not allocated" << endl;
		return 0;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}




void singleList::insertBegin()
{
	int value;
	cout << "Enter value to be inserted: ";
	cin >> value;
	struct node *temp , *p;
	temp = createNode(value);
	if( start == NULL )
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;

	}
	cout << "Element inserted at beginning" << endl;
}





void singleList::insertLast()
{
	int value;
	cout << "Enter value to be inserted: ";
	cin >> value;
	struct node *temp , *s;
	temp = createNode(value);
	s = start;
	while(s->next != NULL )
	{
		s = s->next;
	}
	temp->next = NULL;
	s->next = temp;
	cout << "Element inserted at last" << endl;
}





void singleList::insertPos()
{
	int value , pos , counter = 0 ;
	cout << "Value to be inserted: " ;
	cin >> value;
	struct node *temp , *s , *ptr;
	temp = createNode(value);
	cout << "Enter the position at which node to be inserted: " ;
	cin >> pos;
	int i ;
	s = start ;
	while( s != NULL )
	{
		s = s->next;
		counter++;
	}
	if( pos == 1 )
	{
		if(start == NULL )
		{
			start = temp;
			start->next = NULL;
		}
		else
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if( (pos > 1 ) && (pos <= counter) ) 
	{
		s = start;
		for( i = 1 ; i < pos ; i++ )
		{
			ptr = s;
			s = s->next;
		}
		ptr->next = temp;
		temp->next = s;
	}
	else
	{
		cout << "Position not within valid range" << endl;
	}
}





void singleList::sort()
{
	struct node *ptr , *s;
	int value;
	if( start == NULL )
	{
		cout << "List is empty" << endl;
		return ;
	}
	ptr = start;
	while( ptr != NULL )
	{
		for( s = ptr->next ; s != NULL ; s = s->next )
		{
			if(ptr->info > s->info )
			{
				value = ptr->info;
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr=ptr->next;
	}
}




void singleList::deletePos()
{
	int pos(0);
	int i(0);
	int counter(0);
	if( start == NULL )
	{
		cout << "List empty" << endl;
		return ;
	}
	cout << "Enter position of value to be deleted: " ;
	cin >> pos;
	struct node *s , *ptr;
	s = start;
	if( pos == 1 )
	{
		start = s->next;
	}
	else
	{
		while( s != NULL )
		{
			s = s->next;
			counter++;
		}
		if( (pos > 0 ) && (pos <= counter) ) 
		{
			s = start;
			for( i = 1 ; i < pos ; i++ )
			{
				ptr = s;
				s = s->next;

			}
			ptr->next = s->next;
		}
		else
		{
			cout << "Position out of range" << endl;
		}
		free(s);
		cout << "Element deleted" << endl;
	}
}


void singleList::update()
{
	int value(0);
	int pos(0);
	int i(0);
	if( start == NULL )
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter node position to be updated: " ;
	cin >> pos;
	cout << "Enter node's new value: " ;
	cin >> value;
	struct node *s , *ptr;
	s = start;
	if( pos == 1 )
	{
		start->info = value;
	}
	else
	{
		for( i = 0 ; i < pos - 1 ; i++ )
		{
			if( s == NULL )
			{
				cout << "There are less than " << pos << " elements." ;
				return;
			}
			s = s->next;
		}
		s->info = value;
	}
	cout << "Node updated" << endl;
}




void singleList::search()
{
	int value(0);
	int pos(0);
	bool flag(false);
	if( start == NULL )
	{
		cout << "List is empty" << endl;
		return ;
	}
	cout << "Enter value to be searched: " ;
	cin >> value;
	struct node *s;
	s = start ;
	while( s != NULL )
	{
		pos++;
		if( s->info == value)
		{
			flag = true;
			cout << "Element " << value << " is found at position " << pos << endl;
		}
		s = s->next;
	}
	if( !flag ) 
	{
		cout << "Element " << value << " not found in the list. " << endl;
	}
}



void singleList::reverse()
{
	struct node *ptr1 , *ptr2 , *ptr3;
	if( start == NULL )
	{
		cout << "List is empty" << endl;
		return;
	}
	if( start->next == NULL )
	{
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while( ptr3 != NULL )
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2;
}




void singleList::display()
{
	struct node *temp;
	if( start == NULL )
	{
		cout << "List is empty" << endl;
		return ;
	}
	temp = start;
	cout << "Elements of the list are as follows" << endl;
	while( temp != NULL )
	{
		cout << temp->info << "-> " ;
		temp = temp->next;



	}
	cout << " NULL " << endl;
}



