#include<iostream>
#include<string>
#include<vector>

using namespace std;

string month[] = {"January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" };


class Company
{
protected:
	std::string m_strName;
	std::string m_strTicker;
	int *x[];
	Company(std::string strName , std::string strTicker)
	: m_strName(strName) ,
	  m_strTicker(strTicker)
	{

	}
public:
	std::string GetName()		{ return m_strName; }
	std::string GetTicker()		{ return m_strTicker; }
	
	int *GetNumber() 
	{
		
		return x; 
	}
};

class Walmart: public Company
{

public:
	Walmart(string strName , string strTicker)
	: Company(strName , strTicker)
	{

	}
	int SetNumber()
	{
		x[0] = 104;
		return x;
	}


};


void PrintCompany(Company &rCompany)
{
	cout << "We are currently dealing with: " << rCompany.GetName() << endl;
	cout << rCompany.GetName() << " has the ticker symbol: " << rCompany.GetTicker() << endl;
	// rCompany.SetNumber();
	cout << "Heres the random number, x: " << rCompany.GetNumber() << endl;
	
}






int main()
{
	Walmart cWalmart("Walmart" , "WMT");
	cWalmart.SetNumber() ;
	PrintCompany(cWalmart);



	return 0;
}