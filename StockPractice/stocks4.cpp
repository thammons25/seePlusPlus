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
	string m_strTicker;
	double *m_dStocks;
public:
	Company()
	{
		m_strName = "0";
		m_strTicker = "0";
		*m_dStocks = 0.0;
	}
	void setName(string strName)
	{
		m_strName = strName;
	}
	string getName()
	{
		return(m_strName);
	}
	void setTicker(string strTicker)
	{
		m_strTicker = strTicker;

	}
	string getTicker()
	{
		return(m_strTicker);
	}
	virtual const double *SetStock() = 0;
	
};

class Walmart: public Company
{
public:
	Walmart()
	{
		m_strName = "Walmart";
		m_strTicker = "WMT";
		m_dStocks = new double[120];
		
	}

	virtual const double *SetStock()
	{
		double dStockPrice[12] = {68.93 , 70.11 , 70.78 , 75.00 , 77.85 , 75.06 , 74.99 , 78.42 , 73.48 , 73.87 , 76.97 , 80.86 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}	
		for( int i(0) ; i < 12 ; i++ )
		{
			cout << month[i] << "      \t "<<  m_dStocks[i] << endl;
		}
		delete[] m_dStocks;
		m_dStocks = nullptr;
		return m_dStocks;
		
	}


	

};

class Exxon: public Company
{
public:
	Exxon()
	{
		m_strName = "Exxon Mobil";
		m_strTicker = "XOM";
		m_dStocks = new double[120];
	}
	virtual const double *SetStock()
	{
		double dStockPrice[12] = { 87.79 , 90.44 , 89.07 , 90.13 , 88.52 , 90.53 , 90.39 , 92.69 , 87.70 , 85.99 , 89.74 , 93.27 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		for( int j(0) ; j < 12 ; j++ )
		{
			cout << month[j] << "      \t " << m_dStocks[j] << endl;

		}
		delete[] m_dStocks;
		m_dStocks = nullptr;
		return m_dStocks;
		
	}

};

class Apple: public Company
{
public:
	Apple()
	{
		m_strName = "Apple";
		m_strTicker = "AAPL";
		m_dStocks = new double[120];
	}
	virtual const double *SetStock()
	{
		double dStockPrice[12] = {553.82 , 459.11 , 438.00 , 441.90 , 444.46 , 450.73 , 402.69 , 455.75 , 493.10 , 478.45 , 524.02 , 558.00 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		for( int j(0) ; j < 12 ; j++ )
		{
			cout << month[j] << "      \t " << m_dStocks[j] << endl;
		}
		cout << endl;
		delete[] m_dStocks;
		m_dStocks = nullptr;
		return m_dStocks;
		
	}

};



class GE: public Company
{
public:
	GE()
	{
		m_strName = "General Electric";
		m_strTicker = "GE";
		m_dStocks = new double[120];
	}
	virtual const double *SetStock()
	{
		double dStockPrice[15] = { 21.51 , 22.43 , 23.02 , 23.03 , 22.10 , 23.37 , 23.21 , 24.60 , 23.31 , 23.94 , 26.05 , 26.65 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		for( int j(0) ; j < 12 ; j++ )
		{
			cout << month[j] << "      \t " << m_dStocks[j] << endl;
		}
		cout << endl;
		delete[] m_dStocks;
		m_dStocks = nullptr;
		return m_dStocks;
		
	}
};



class CVS: public Company
{
public:
	CVS()
	{
		m_strName = "CVS";
		m_strTicker = "CVS";
		m_dStocks = new double[120];
	}
	virtual const double *SetStock()
	{
		double dStockPrice[12] = { 49.02 , 51.63 , 51.07 , 54.75 , 58.97 , 57.67 , 57.72 , 62.01 , 58.44 , 56.76 , 62.42 , 67.40 };
		for( int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		for( int j(0) ; j < 12 ; j++ )
		{
			cout << month[j] << "      \t " << m_dStocks[j] << endl;
		}
		cout << endl;

		return m_dStocks;
		delete[] m_dStocks;
		m_dStocks = nullptr;
		
	}
	void random()
	{
		cout << m_dStocks[3] << endl;
	}
};

void Report2(Company &rCompany)
{
	cout << rCompany.SetStock() << endl;



}

void real(CVS rCVS)//proof of access to class data
{
	rCVS.random();

}



































void Report(Company &rCompany)
{
	rCompany.SetStock() ;

}























































int main()
{
	// Walmart cWalmart;
	// Report(cWalmart);

	// Exxon cExxon;
	// Report(cExxon);

	// Apple cApple;
	// Report(cApple);

	// GE cGE;
	// Report(cGE);

	CVS cCVS;
	Report2(cCVS);
	real(cCVS);
	return 0;
}
