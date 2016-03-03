#include<iostream>
#include<queue>
using namespace std;


const int INPUT_SIZE = 20;
const int BUCKET_K = 10;

void print( int *input )
{
	for( int i(0) ; i < INPUT_SIZE ; i++ )
	{
		cout << input[i] << " " ;

	}
	cout << endl;
}


int has(int n)
{
	return(n/5);
}

void insertionSort( int *input , int len )
{
	while( len-- > 0 )
	{
		if( input[len] > input[len+1])
		{
			int temp = input[len];
			input[len] = input[len+1];
			input[len+1] = temp;
		}
		else 
			return;
	}
}


void bucektSort( int *input)
{
	queue<int>*buckets[BUCKET_K];
	for( int i(0) ; i < BUCKET_K ; i++ )
	{
		buckets[i] = new queue<int>;

	}
	for( int j(0) ; j < INPUT_SIZE ; j++ )
	{
		int hashValue = hash(input[j]);
		if(hashValue >= BUCKET_K)
		{
			hashValue = BUCKET_K - 1;
		}
		buckets[hashValue]->push(input[j]);
	}

	int outputIndex(0) ;
	for( int k(0) ; k < BUCKET_K ; k++ )
	{
		if( buckets[k]-> size() == 1)
		{
			input[outputIndex] = buckets[k]-> front();
			cout << buckets[i]-> front() << " | " ;
			buckets[k]-> pop();

		}
		if( buckets[k]-> empty() )
		{
			while(!buckets[k]-> empty() )
			{
				input[outputIndex] = buckets[k]->front();
				insertionSort( input , outputIndex );
				cout << buckets[k]->front() << " " ;
				buckets[k]->pop();
				outputIndex++;
			}
			cout << " | ";
		}
	}
	for( int r(0) ; r < BUCKET_K ; r++ )
	{
		delete buckets[r];
	}
}


int main()
{
	int input[INPUT_SIZE] = { 25 , 44 , 13 , 34 , 27 , 11 , 11 , 9 , 45 , 37 , 27 , 28 , 42 , 6 , 49 , 31 , 37 , 23 , 14 , 41 };
	cout << "input: ";
	print(input);
	cout << "Bucket: ";
	bucketSort(input);
	cout << "\nOutput: ";
	print(input);

	return 0;
}










