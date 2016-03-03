#include<iostream>

using namespace std;


double Addition(double numOne , double numTwo )
{
	double addSum(numOne + numTwo);
	return(addSum);

}

double Subtraction( double numOne , double numTwo )
{
	double subDiff(numOne - numTwo);
	return(subDiff);
}

double Multiply( double numOne , double numTwo )
{
	double multProd( numOne * numTwo );
	return(multProd);
}


double Divide( double numOne , double numTwo )
{
	double divQuot( numOne / numTwo );
	return(divQuot);
}


int main()
{
	cout << "Enter num: ";
	double numOne;
	cin >> numOne;
	cout << endl;

	cout << "1 = add" << endl;
	cout << "2 = sub" << endl;
	cout << "3 = mult" << endl;
	cout << "4 = div " << endl;
	cout << "Enter: " ;
	int pickOperator;
	cin >> pickOperator;

	cout << "Enter num: " ;
	double numTwo;
	cin >> numTwo;
	cout << endl;

	switch(pickOperator)
	{
		case 1:
		{
			cout << "Sum: " << Addition(numOne , numTwo) << endl;
			break;
		}
		case 2:
		{
			cout << "Diff: " << Subtraction(numOne , numTwo) << endl;
			break;
		}
		case 3:
		{
			cout << "Product: " << Multiply(numOne , numTwo ) << endl;
			break;

		}
		case 4: 
		{
			cout << "Quotient: " << Divide(numOne , numTwo ) << endl;
			break;
		}
		default:
		{
			cout << "?????" << endl;
		}

	}
	return 0;


}















