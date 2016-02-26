#include<iostream>
#include<string>

int main()
{
	using namespace std;
	int v(0);
	int A[] = { 10 , 20 , 30 , 40 , 50 , 60 };
	cout << "Enter number to search for: ";
	cin >> v;
	int dummy(-1);
	int aLength( (sizeof A) / (sizeof(int) ) );
	for( int i(0) ; i < aLength ; i++ )
	{
		if( A[i] == v)
			dummy = i;
	} 
	if(dummy == -1)
		cout << v << " is not in A" << endl;
	else
		cout << "I found " << v << " element " << (dummy+1) << " of A." << endl;

	
	
	return 0;
}