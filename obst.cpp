#include<stdio.h>
#include<stdlib.h>

#define nmax 20



typedef struct OBST
{
	int key;
	struct OBST *left , *right;
}
OBST;

int C[nmax][nmax];
int W[nmax][nmax];
int R[nmax][nmax];
int q[nmax];
int p[nmax];
int numberOfKeys;
int keys[nmax];
OBST *ROOT;

void computeWCR()
{
	int x , min ;
	int i , j , k , h , m ;
	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		W[i][i] = q[i];
		for( j = i+1 ; j <= numberOfKeys ; j++ )
		{
			W[i][j] = W[i][j-1] + p[j] + q[j];
		}


	}

	//construct cost matrix c and root matrix r 
	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		C[i][i] = W[i][i];

	}
	for( i = 0 ; i <= numberOfKeys-1 ; i++ )
	{
		j = i+1;
		C[i][j] = C[i][i] + C[j][j] + W[i][j];
		R[i][j] = j;
	}
	for( j = 2 ; j <= numberOfKeys ; h++ )
	{
		for( i = 0 ; i <= numberOfKeys-h ; i++ )
		{
			j = i+h;
			m = R[i][j-1];
			min = C[i][m-1] + C[m][j];
			for( k = m+1 ; k <= R[i+1][j] ; k++ )
			{
				x = C[i][k-1] + C[k][j];
				if( x < min )
				{
					m = k;
					min = x;
				}
			}
			C[i][j] = W[i][j] + min;
			R[i][j] = m;
		}

	}
	printf("\nWeight Matrix, W\n");
	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		for( j = i ; j <= numberOfKeys ; j++ )
		{
			printf("%d  " , W[i][j]);

		}
		printf("\n");
	}

	printf("\nCost Matrix, C\n" );
	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		for( j = i ; j <= numberOfKeys ; j++ )
		{
			printf("%d  " , C[i][j]);

		}
		printf("\n");
	}

	printf("\nRoot Matrix, R\n");
	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		for( j = i ; j <= numberOfKeys ; j++ )
		{
			printf("%d  " , R[i][j]);
		}
		printf("\n");
	}
}


OBST *constructOBST( int i , int j )
{
	OBST *p;

	if( i == j )
		p = NULL;
	else
	{
		p = new OBST;
		p->key = keys[R[i][j]];
		p->left = constructOBST( i , R[i][j] - 1 );
		p->right = constructOBST( R[i][j] , j );
	}
	return p;
}


void Display(OBST *ROOT , int nivel )
{
	int i;
	if( ROOT != 0 )
	{
		Display( ROOT->right , nivel+1 );
		for( i = 0 ; i <= nivel ; i++ )
		{
			printf("     ");

		}
		printf("%d\n" , ROOT->key);
		Display( ROOT->left , nivel + 1);
	}
}




void optimalBST()
{
	float averageCost;
	computeWCR();
	printf("C[0] = %d W[0] = %d\n" , C[0][numberOfKeys] , W[0][numberOfKeys]);
	averageCost = C[0][numberOfKeys] / (float)W[0][numberOfKeys];
	printf("The Cost Per Weight Ratio: %f\n" , averageCost );
	ROOT = constructOBST( 0 , numberOfKeys );
}



int main( int argc , char *argv[] )
{
	int i , k;
	printf("Input Number Of Keys: " );
	scanf("%d" , &numberOfKeys);
	for( i = 0 ; i <=numberOfKeys ; i++ )
	{
		printf("key[%d] = " , i );
		scanf("%d" , &keys[i]);
		printf("frequency = ");
		scanf("%d" , &p[i]);
	}

	for( i = 0 ; i <= numberOfKeys ; i++ )
	{
		printf("q[%d] = " , i );;
		scanf("%d" , &k );
		switch(k)
		{
			case 1:
			{
				optimalBST();
				break;

			}
			case 2:
			{
				Display(ROOT , 0 );
				break;

			}
			case 3:
			{
				exit(0);
				break;
			}
		}
	}
	return 0;
}






















































































