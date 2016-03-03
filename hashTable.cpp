#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>

#define sizeKey 			16
#define sizeValueOne 		64
#define sizeValueTwo		16
#define defaultTableSize 	101

using namespace std;


struct NODE 
{
	Node(const char *Key1 = "\0" , const char *fName = "\0" , const char *tele = "\0" const double sal = 0.0)
	{
		strcpy(Key , Key1);
		strcpy(FullName , fName);
		strcpy(TeleNo , tele);
		Salary = sal;
		Tax = 0.005 * Salary;
		next = NULL;
	}
	char Key[sizeKey];
	char FullName[sizeValueOne];
	char TeleNo[sizeValueTwo];
	double Salary;
	double Tax;
	Node *next;
};


class Hashtable
{
private:
	int tableSize;
	NODE **table;
	int size;
	long hashString( char *Key);
	NODE *find( char *Key);
	NODE *currentEntry;
	int currentIndex;
public:
	Hashtable( int T = defaultTableSize);
	virtual ~Hashtable();
	bool put(NODE *);
	bool get(NODE *);
	bool contains( char *Key);
	bool remove(char *Key);
	void removeAll();
	int getSize();
	void initIterator();
	bool hasNext();
	void getNextKey();
	friend void disp(NODE *);

};

Hashtable::Hashtable(int T)
{
	size = 0;
	tableSize = T;
	table = new NODE*[tableSize];
	for( int i(0); i < tableSize ; i++ )
	{
		table[i] = NULL;
	}

}

Hashtable::~Hashtable()
{
	removeAll();
	delete[] table;
}

void disp(NODE *N1)
{
	cout << "\nKey: " << N1->Key << "\nFull Name: " << N1->FullName << "\nTelephone: " << 
	   N1->teleNo << "\nSalary: " << setprecision(12) << N1->Salary << "\nTax: " << N1->Tax << endl;
}


bool Hashtable::put(NODE *N)
{
	if( find(N->Key) != NULL )
	{
		return false;
	}
	NODE *entry = new NODE(N->Key , N->FullName , N->TeleNo , N->Salary);
	int bucket = hashString(N->Key);
	entry->next = table[bucket];
	table[bucket] = entry;
	size++;
	return true;
}


bool Hashtable::get(NODE *N)
{
	NODE *temp = find(N->Key);
	if( temp == NULL )
	{
		N->FullName[0] = '\0';
		return false;
	}
	else
	{
		strcpy(N->FullName , temp->FullName);
		strcpy(N->TeleNo , temp->TeleNo);
		N->Salary = temp->Salary;
		N->Tax = temp->Tax;
		return true;
	}
}



bool Hashtable::contains( char *Key )
{
	if(find(Key) == NULL )
	{
		return false;
	}
	else
	{
		return true;
	}
}



bool Hashtable::remove( char *Key)
{
	int bucket = hashString(Key);
	NODE *temp = table[bucket];
	if( temp == NUL )
	{
		return false;
	}
	else if(strcmp(Key , temp->Key) == 0)
	{
		table[bucket] = temp->net;
		delete temp;
		size--;
		return true;
	}
	else
	{
		NODE *tempNext = temp->next;
		while(tempNext != NULL )
		{
			if(strcmp(Key , tempNext->Key) == 0)
			{
				temp->next = tempNext->next;
				delete tempNext;
				size--;
				return true;
			}
			temp = temp->next;
			tempNext = tempNext->next;
		}
	}
	return false;
}



void Hashtable::removeAll()
{
	for( int i(0) ; i < tableSize ; i++ )
	{
		NODE *temp = table[i];
		while( temp != NULL )
		{
			NODE *next = temp->next;
			disp(temp);
			delete temp;
			temp = next;
		}
	}
	size = 0;

}



int Hashtable::getSize()
{
	return size;
}



NODE *Hashtable::find(char *Key)
{
	int bucket = hashString(Key);
	NODE *temp = table[bucket];
	while( temp != NULL )
	{
		if(strcmp(Key , temp->Key) == 0 )
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}




long Hashtable::hashString(char *Key)
{
	int n = strlen(Key);
	long h = 0;
	for( int i(0) ; i < n ; i++ )
	{
		h = ( h << 3 ) ^ Key[i];
	}
	return abs(h % tableSize);
}


void Hashtable::initIterator()
{
	currentEntry = NULL ;
	currentIndex = tableSize;
	for( int i(0) ; i < tableSize ; i++ )
	{
		if( table[i] == NULL )
		{
			continue; 
		}
		else
		{
			currentEntry = table[i];
			currentIndex = i;
			break;
		}
	}
}


bool Hashtable::hasNext()
{
	if( currentEntry == NULL )
	{
		return false;
	}
	else
	{
		return true;
	}
}



void Hashtable::getNextKey( char *Key )
{
	if(currentEntry == NULL )
	{
		Key[0] = '\0';
		return;
	}
	strcpy(Key , currentEntry->Key);
	if( currentEntry->next != NULL )
	{
		currentEntry = currentEntry->next;
	}
	else
	{
		for( int i(currentIndext+1) ; i < tableSize ; i++ )
		{
			if(table[i] == NULL)
			{
				continue;
			}
			currentEntry = table[i];
			currentIndex = i;
			return ;
		}
		currentEntry = NULL;
		currentIndex = tableSize;
	}
}



void dispAll(Hashtable *hashtable);



int main()
{
	char temp1[sizeKey];
	Hashtable *hashtable = new Hashtable();

	NODE N1("399" , "Miriam" , "203392804" , 22123.24);
	if( !hashtable->contains(N1.Key))
	{
		cout << "\nAdding node: " ;
		disp(&N1);
		hashtable->put(&N1);
	}

	strcpy(N1.Key , "314");
	strcpy(N1.FullName , "Zeke");
	strcpy(N1.TeleNo , "2033300132");
	N1.Salary = 99124.56;
	if( !hashtable->contains(N1.Key))
	{
		cout << "Adding Node: " ;
		disp(&N1);
		hashtable->put(&N1);

	}
	dispAll(hashtable);


	return 0;

}


void dispAll(Hashtable *hashtable)
{
	NODE N1;
	cout << "\n\nCurrent Nodes In Hashtable: " << endl;
	hashtable->initIterator();
	while(hashtable->hasNext() )
	{
		hashtable->getNextKey(N1.Key);
		hashtable->get(&N1);
		disp(&N1);
	}
}











































































































































































































































