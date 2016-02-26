//THIS WORKS ON 7/15/2015
#include<iostream>
#include<cmath>

int left( int iIndex )
{
	return( (iIndex << 1) + 1 );

}

int right( int iIndex )
{
	return( (iIndex << 1) + 2 );

}

int parent( int iIndex )
{
	return( (iIndex - 1) >> 1);
}

void swap(int &irx , int &iry )
{
	int temp = irx;
	irx = iry;
	iry = temp;
}

int swapWithChild( int iIndex , int *ipHeap , int iSize )
{
	int iLeft = left(iIndex);
	int iRight = right(iIndex);
	int iLargest = iIndex;
	if( iRight < iSize )
	{
		if( ipHeap[iLeft] <= ipHeap[iRight] )
		{
			iLargest = iRight;
		}
		else
		{
			iLargest = iLeft;
		}
		if( ipHeap[iIndex] > ipHeap[iLargest] )
		{
			iLargest = iIndex;
		} 
		else if( iLeft < iSize )
		{
			if( ipHeap[iIndex] < ipHeap[iLeft] )
			{
				iLargest = iLeft;
			}
		}
		if( ipHeap[iIndex] < ipHeap[iLargest] )
		{
			swap( ipHeap[iIndex] , ipHeap[iLargest] );
		}
		

	}
	return iLargest;
}

void removeRoot( int *ipHeap , int iSize )
{
	ipHeap[0] = ipHeap[iSize - 1];
	--iSize;
	int iLasti = 0;
	int i = swapWithChild( 0 , ipHeap , iSize );
	while( i != iLasti )
	{
		iLasti = i;
		i = swapWithChild( i , ipHeap , iSize );
	}
}



int swapWithParent( int i , int *ipHeap )
{
	if( i < 1 )
	{
		return(i);
	}
	int iParent = parent(i);
	if( ipHeap[i] > ipHeap[iParent] )
	{
		swap( ipHeap[i] , ipHeap[iParent] );
		return( iParent );
	}
	else
	{
		return(i);
	}
}


void addElement( int iNewEntry , int *ipHeap , int iSize )
{
	ipHeap[iSize] = iNewEntry;
	int iLasti = iSize;
	int i = swapWithParent( iLasti , ipHeap );
	while( iLasti != i )
	{
		iLasti = i;
		i = swapWithParent(i , ipHeap);
	}
}



void OutputHeap( int *ipHeap , int iSize )
{
	using namespace std;
	int iDepth(0);
	int iCopy(0);
	while( iCopy > 0 )
	{
		iCopy >>= 1;
		++iDepth;
	}
	int maxWidth = (1 << iDepth);
	int charWidth = 4*maxWidth;
	int iEntry(0);
	for(int i(0) ; i < iDepth ; ++i )
	{
		int iPowerOfTwo = (1 << i );
		for( int j(0) ; j < iPowerOfTwo ; ++j )
		{
			int iSpacesBefore = ( (charWidth / (1 << (i+1) ) ) -1 );
			for(int k(0) ; k < iSpacesBefore ; ++k)
			{
				cout << " " ;
			}
			if( ipHeap[iEntry] < 10 )
			{
				cout << " " ;
			}
			cout << ipHeap[iEntry];
			++iEntry;
			if( iEntry >= iSize)
			{
				cout << endl;
				return;
			}
			for( int k(0) ; k < iSpacesBefore ; ++k )
			{
				cout << " " ;
			}

		}
		cout << endl << endl;
	}
}


void outputArray( int *ipArray , int iSize )
{
	using namespace std;
	for( int i(0) ; i < iSize ; ++i )
	{
		cout << ipArray[i] << " " ;
	}
	cout << endl;
}



int main()
{
	using namespace std;
	srand(1);
	int iaArray[15];
	for( int i(0) ; i < 15 ; ++i )
	{
		iaArray[i] = ( rand() % 100 );
	}

	for( int i(0) ; i < 15 ; ++i )
	{
		addElement(iaArray[i] , iaArray , i );
		outputArray( iaArray , i+1 );
		cout << endl;
		OutputHeap( iaArray , i+1 );
		cout << "-------------------------------" << endl;

	}
	for( int i(0) ; i < 14 ; ++i )
	{
		removeRoot( iaArray , 15 - i );
		outputArray( iaArray , 14-i );
		cout << endl;
		OutputHeap( iaArray , 14-i );
		cout << "--------------------------------" << endl;

	}
	return 0;
}















