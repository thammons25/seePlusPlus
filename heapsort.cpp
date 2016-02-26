#include<iostream>

void maxHeapify( int a[] , int i , int n )
{
	int l;
	int r;
	int largest;
	int loc;
	l *= i;
	r = (2*i + 1);
	if( (l <= n) && a[l] > a[i] )
		largest = l;
	else
		largest = i;
	if( (r <= n) && (a[r] > a[largest]) )
		largest = r;
	if( largest != i )
	{
		loc = a[i];
		a[i] = a[largest];
		a[largest] = loc;
		maxHeapify( a , largest , n );
	}
}


void buildMaxheap( int a[] , int n )
{
	for( int k = n/2 ; k >= 1 ; k-- )
	{
		maxHeapify( a , k , n );
	}
}



void heapsort( int a[] , int n )
{
	buildMaxheap( a , n );
	int i;
	int temp;
	for( i = n ; i >= 2 ; i-- )
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		maxHeapify( a , 1 , i-1);
	}
}




int main()
{
	using namespace std;
	int n;
	cout << "Enter array size: ";
	cin >> n;
	int a[n];
	cout << "Enter elements in array: " ;
	for( int i(1) ; i <= n ; i++ )
	{
		cin >> a[i];
	}
	heapsort( a , n );
	cout << "::::::::::SORTED FORM:::::::::::" << endl;
	for( int i(1) ; i <= n ; i++ )
	{
		cout << a[i] << endl;
	}

	return 0;
}



















