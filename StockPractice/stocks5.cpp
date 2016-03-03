#include<iostream>
#include<string>
#include<vector>

//HERE IS THE AMOUNT OF SPACE WE NEED IN ORDER TO HAVE COLUMN-LINED DATES AND STOCK PRICES
//cout << month[j] << "      \t " << m_dStocks[j] << endl;
using namespace std;
const string month[] = {"January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , 
"September" , "October" , "November" , "December" };


class Company
{
protected:
	string m_strName;
	int m_nYear;
	double *m_dStocks;
public:
	Company( string strName , int nYear )
	{
		m_strName = strName;
		m_nYear = nYear;
		*m_dStocks = 0.0;
	}
	string GetName()			{ return m_strName; }
	int GetYear()				{ return m_nYear; }
	virtual const double *SetStock() = 0;
};

class WellsFargo: public Company
{
public:
	WellsFargo(string strName , int nYear )
	: Company( strName , nYear )
	{
		m_dStocks = new double[15];
	}
	virtual const double *SetStock()
	{
		double dStockPrice[12] = { 35.03 , 35.06 , 34.94 , 37.02 , 37.90 , 40.83 , 41.56 , 44.19 , 41.65 , 41.37 , 42.72 , 44.11 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		return m_dStocks;
		delete[] m_dStocks;
		m_dStocks = nullptr;

	}
};


void PrintStock(Company &rCompany)
{
	cout << "For year " << rCompany.GetYear() << ", " << rCompany.GetName() << " had monthly open stock prices as follows\n" << endl;
	for( int i(0) ; i < 12 ; i++ )
	{
		cout << month[i] <<  "      \t " << rCompany.SetStock()[i] << endl;
	}
	cout << endl;
}


int main()
{
	// cout << "Enter Company Name: ";
	// string userCompany;
	// getline( cin , userCompany );
	// cout << "You entered: " << userCompany << endl;
	// cout << "Enter year: " ;
	// int userYear;
	// cin >> userYear;

	WellsFargo cWellsFargo( "Wells Fargo" , 2013 );
	PrintStock(cWellsFargo);

	return 0;
}





double kadane( double )





int kadane( int A[] , int n)
{
	int maxSum(-100);
	int maxStart(0);
	int maxEnd(0);
	int currentMax(0);
	int currentStart(0);
	for( int i(0) ; i < n ; i++ )
	{
		currentMax = currentMax + A[i];
		if( currentMax > maxSum )
		{
			maxSum = currentMax;
			maxStart = currentStart;
			maxEnd = i;
		}
		else if( currentMax < 0 )
		{
			currentMax = 0;
			currentStart = i+1;
		}
	}
	return(maxSum);

}



int main()
{
	using namespace std;
	int A[] = { 9 , -10 , 2 , -4 , 0 , 4 , 2 , -6 , 12};
	int aSize( sizeof A / sizeof(int) );
	int myMax(0);
	myMax = kadane( A , aSize );
	cout << myMax << endl;





	return 0;
}






























