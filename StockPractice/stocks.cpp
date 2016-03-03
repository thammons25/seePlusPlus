#include<iostream>
#include<string>
#include<vector>


class Company
{
protected:
	double *m_dStockPrice[];
public:
	Company(double m_dStockPrice)
	{

	}
	virtual const char* CompnayName() = 0;
	virtual const char* StockTicker() = 0;
	virtual const char* Analysis() = 0;

	double SetStockPrice()
	{
		return m_dStockPrice;
	}

};


class Walmart: public Company
{
public:
	Walmart( double *dStockPrice[] )
	: Company( *dStockPrice[] )
	{

	}
	double SetStockPrice()
	{
		dStockPrice[] = { 68.93 , 70.11 , 70.78 , 75.00 , 77.85 , 75.06 , 74.99 , 78.42 , 73.48 , 73.87 , 76.97 , 80.86 };
	}
	virtual const char *CompanyName()
	{
		return "Walmart";
	}
	virtual const char *StockTicker()
	{
		return "WMT";
	}
	virtual const char *Analysis()
	{
		return "Walmart is currently the number one Fortune 500 company.";
	}

};





