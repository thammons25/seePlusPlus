#include<iostream>
using namespace std;

void print( int *input , int n)
{
	for( int i(0) ; i < n ; i++ )
	{
		cout << input[i] << "\t";
	}
}



void radixSort( int *input , int n )
{
	int i(0);
	int maxNum = input[0];
	for( i = 1; i < n ; i++ )
	{
		if( input[i] > maxNum )
		{
			maxNum = input[i];
		}
	}
	int exp(1);
	int *tmpBuffer = new int[n];
	while( (maxNum / exp ) > 0 )
	{
		int decimalBucket[10] = {0};
		for( i = 0 ; i < n ; i++ )
		{
			decimalBucket[input[i] / exp % 10 ]++;
		}
		for( i = 1 ; i < 10 ; i++ )
		{
			decimalBucket[i] += decimalBucket[i-1];
		}
		for( i = n-1 ; i >= 0 ; i-- )
		{
			tmpBuffer[--decimalBucket[input[i] / exp % 10 ]] = input[i] ;
		}
		for( i = 0 ; i < n ; i++ )
		{
			input[i] = tmpBuffer[i];
		}
		exp *= 10;
		cout << "\nPASS		";
		print( input , n);

	}
}



const int inputSize = 10;



int main()
{
	int input[inputSize] = { 143 , 123 , 222 , 196 , 235 , 9 , 905 , 449 , 543 , 373 };
	cout << "Input:		" ;
	print(input , inputSize );
	radixSort(input , inputSize);
	cout << "\nOutput:		";
	print( input , inputSize );
	cout << endl;
	return 0;
}








