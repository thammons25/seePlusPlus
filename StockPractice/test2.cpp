#include<iostream>
#include<string>
using namespace std;



class Company
{
protected:
	string m_strName;
	double m_dStockPrice;
public:
	Company()
	{
		m_strName = "N/A";
		m_dStockPrice = 0.0;
	}
	Company(string strName , double dStockPrice )
	{
		m_strName = strName;
		m_dStockPrice = dStockPrice;
	}
	string SetName()				{return m_strName;}
};

class Walmart: public Company
{
protected:

public:
	Walmart(string strName , double dStockPrice)
	: Company(strName , dStockPrice) 

	{

	}

	void SetStock()
	{
		*dStockPrice[12] = {68.93 , 70.11 , 70.78 , 75.00 , 77.85 , 75.06 , 74.99 , 78.42 , 73.48 , 73.87 , 76.97 , 80.86 };

	}
	double GetStock()
	{
		return m_dStockPrice;
	}

};




int main()
{
	return 0;
}