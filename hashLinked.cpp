#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;

const int TABLE_SIZE = 128;

class HashNode
{
public:
	int key;
	int value;
	HashNode *next;
	HashNode(int key , int value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};


class HashMap
{
private:
	HashNode** htable;
public:
	HashMap()
	{
		htable = new HashNode*[TABLE_SIZE];
		for( int i(0) ; i < TABLE_SIZE ; i++ )
		{
			htable[i] = NULL;
		}
	}
		~HashMap()
		{
			for( int i(0) ; i < TABLE_SIZE ; i++ )
			{
				HashNode* entry = htable[i];
				while( entry != NULL )
				{
					HashNode *prev = entry;
					entry = entry->next;
					delete prev;
				}
			}
			delete[] htable;
		}


		int HashFunc( int key )
		{
			return key % TABLE_SIZE;
		}

		void Insert( int key , int value )
		{
			int hashVal = HashFunc(key);
			HashNode *prev = NULL;
			HashNode *entry = htable[hashVal];
			while( entry != NULL )
			{
				prev = entry;
				entry = entry->next;
			}
			if( entry == NULL )
			{
				entry = new HashNode(key , value);
				if( prev == NULL )
				{
					htable[hashVal] = entry;
				}
			}
			else
			{
				prev->next = entry;
			}
			else
			{
				entry->value = value;
			}
		}


		void Remove( int key )
		{
			int hashVal = HashFunc(key);
			HashNode *entry = htable[hashVal];
			HashNode *prev = NULL;
			if( entry == NULL || entry->key != key )
			{
				cout << "No element found at key: " << key << endl;
				return;
			}
			while( entry->next != NULL )
			{
				prev = entry;
				entry = entry->next;
			}
			if( prev != NULL )
			{
				prev->next = entry->next;
			}
			delete entry;
			cout << "Element Deleted. " << endl;
		}


		int Search( int key )
		{
			bool flag = false;
			int hashVal = HashFunc(key);
			HashNode *entry = htable[hashVal];
			while( entry != NULL )
			{
				if( entry->key == key )
				{
					cout << entry->value << " " ;
					flag = true;

				}
				entry = entry->next;
			}
			if( !flag )
			{
				return -1;

			}

		}

	
};




int main()
{
	HashMap hash;
	int key;
	int value;
	int choice;
	while(1)
	{
		cout << endl;
		cout << "Hash Table Operations" << endl;
		cout << endl;
		cout << "1.Insert Element Into Table" << endl;
		cout << "2.Search For Element From Key" << endl;
		cout << "3.Delete Element At Key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter Selection: " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				cout << "Enter element to be inserted: " ;
				cin >> value;
				cout << "Enter key at which element is to be inserted: " ;
				cin >> key;
				hash.Insert(key , value);
				break;

			}
			case 2:
			{
				cout << "Enter key of element for which you are searching: " ;
				cin >> key;
				cout << "Element at key: " << key << " : " ;
				if( hash.Search(key) == -1 )
				{
					cout << "No element found at " << key << endl;
					continue;
				}
				break;
			}
			case 3:
			{
				cout << "Enter key of element to be deleted: " ;
				cin >> key;
				hash.Remove(key);
				break;
			}
			case 4:
			{
				exit(1);
			}
			default:
			{
				cout << "\nEnter valid selection " << endl;
			}

		}
	}
	return 0;
}


















