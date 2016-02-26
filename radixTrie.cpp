#include<iostream>
#include<cstdlib>
#include<string>

struct node 
{
	char *key;
	int len;
	node *link;
	node *next;
	node( char *x , int n) : len(n) , link(0) , next(0) 
	{
		key = new char[n];
		strncpy(key , x , n);
	}
	~node()
	{
		delete[] key;
	}
};


int prefix( char *x , int n , char *key , int m)
{
	for( int k(0) ; k < n ; k++ )
	{
		if( (k == m) || x[k] != key[k] )
		{
			return k;
		}

	}
	return n;
}


node *find( node *t , char *x , int n = 0 )
{
	if( !n ) n = strlen(x) + 1 ;
	if( !t ) return 0;
	int k = prefix(x,n,t->key , t->len);
	if( k == 0 ) return find(t->next , x , n);
	if( k == n ) return t;
	if( k==t->len ) return find(t->link , x+k , n-k);
	return 0;


}


void split( node *t , int k)
{
	node *p = new node(t->key+k , t->len-k);
	p->link = t->link;
	t->link = p;
	char *a = new char[k];
	strncpy(a,t->key,k);
	delete[] t->key;
	t->key = a;
	t->len = k;
}


node *insert(node *t , char *x , int n=0)
{
	if( !n ) n = strlen(x)+1;
	if( !t ) return new node(x,n);
	int k = prefix(x,n,t->key,t->len);
	if( k == 0 ) t->next = insert(t->next,x,n);
	else if( k < n )
	{
		if( k < t->len )
			split(t,k);
		t->link = insert(t->link , x+k , n-k );
	}
	return t;
}


void join(node *t)
{
	node *p = t->link;
	char *a = new char[t->len+p->len];
	strncpy(a,t->key,t->len);
	strncpy(a+t->len,p->key,p->len);
	delete[] t->key;
	t->key = a;
	t->len += p->len;
	t->link = p->link;
	delete p;
}


node *remove( node *t , char *x , int n = 0 )
{
	if( !n ) n = strlen(x) + 1;
	if( !t ) return 0;
	int k = prefix(x,n,t->key , t->len);
	if( k == n )
	{
		znode *p = t->next;
		delete t;
		return p;
	}
	if( k == 0 ) t->next = remove(t->next , x , n);
	else if( k == t->len )
	{
		t->link = remove(t->link , x+k , n-k );
		if(t->link && !t->link->next)
		{
			join(t);
		}

	}
	return t;
}































