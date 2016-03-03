#include<iostream>
#include<cstlib>

using namespace std;

struct node
{
	int info;
	struct node *list;

} *front , *rear;


class queueList
{
public:
	void insert(int);
	void display();
	void del();
	queueList()
	{
		front = NULL;
		rear = NULL;
	}
}



int main()
{
	int choice;
	int item;
	while(1)
	{
		cout << endl;
		cout << "Operations on Queue " << endl;
		cout << endl;
		cout << "1.Insert Element Into Queue" << endl;
		cout << "2.Delete Element From Queue" << endl;
		cout << "3.Traverse Queue." << endl;
		cout << "4. Quit" << endl;
		cout << "Enter Choice: " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter value to be inserted into queue: ";
				cin >> item;
				ql.insert(item);
				break;
			case 2:
				ql.del();
				break;
			case 3:
				ql.display();
				break;
			case 4:
				exit(1);
				break;
			default:
				cout << "Invalid Choice" << endl;

		}
	}
	return 0;
}


void queueList::insert(int item)
{
	node *tmp;
	tmp = new (struct node);
	tmp->info = item;
	tmp->link = NULL;
	if(front == NULL)
	{
		front = tmp;

	}
	else
	{
		rear->link
	}
}










































































































