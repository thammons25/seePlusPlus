#include<iostream>
#include<string>

int main()
{
	using namespace std;
	int k(0);
	int counter(1);

	int A[] = { 100 , 90 , 70 , 60 , 50 , 40};
	int aLength( (sizeof A) / (sizeof(int) ) );
	cout << "\nOriginal Array: \t";
	for( int d(0) ; d < aLength ; d++ )
	{
		cout << A[d] << " " ;
	}
	// cout << "\n\ncounter: " ;
	for( int i(0) ; i < aLength ; i++ )
	{
		k = A[i];
		for( int j(i+1) ; j < aLength ; j++ )
		{
			if( A[j] < A[i] )
			{
				k = A[i];
				A[i] = A[j];
				A[j] = k;
				// cout << counter << " " ;
				// counter++;
				// cout << "\n";
				// cout << counter << " " ;
				

			}
		}
	}

	cout << "\n\nSelection Sorted Array: ";
	for( int b(0) ; b < aLength ; b++ )
	{
		cout << A[b] << " " ;
	}
	cout << "\n" << endl;
	// cout << "That took: " << counter << " iterations for the worst case scenario.\n";
	return 0;
}