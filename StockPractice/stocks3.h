#ifndef _stocks3.h_INCLUDE
#define _stocks3.h_INCLUDE

#include<iostream>
#incude<string>
using namespace std;

class Walmart: public Company
{
public:
	Walmart()
	{
		m_strName = "Walmart";
		m_strTicker = "WMT";
		m_dStocks = new double[12];
		
	}
	void SetStockPrice()
	{
		double dStockPrice[12] = {68.93 , 70.11 , 70.78 , 75.00 , 77.85 , 75.06 , 74.99 , 78.42 , 73.48 , 73.87 , 76.97 , 80.86 };
		for(int i(0) ; i < 12 ; i++ )
		{
			m_dStocks[i] = dStockPrice[i];
		}
		for(int j(0) ; j < 12 ; j++ )
		{
			cout << month[j] << "      \t " << m_dStocks[j] << endl;
		}
		cout << endl;
	}


};


#endif 