#include<iostream>
#include<string>

using namespace std;
string month[] = {"January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" };

class Company
{
protected:
	std::string m_strName;
	std::string m_strTicker;
	Company(std::string strName , std::string strTicker)
	: m_strName(strName) ,
	  m_strTicker(strTicker)
	{

	}
public:
	std::string GetName()		{ return m_strName; }
	std::string GetTicker()		{ return m_strTicker; }
	virtual const char *f500() = 0;

};

class Walmart: public Company
{
public:
	Walmart(std::string strName , std::string strTicker)
	:Company(strName , strTicker)
	{

	}
	virtual const char *f500()		{ return "Number one on fortune 500 list."; }

};


