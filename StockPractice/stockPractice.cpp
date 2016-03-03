#include<iostream>
#include<string>
#include<vector>

using namespace std;
//walmart , exonn , apple , ge , cvs


class Companies
{
protected:
	std::string m_strName;
	std::string m_strTicker;
	int m_nDate;
	double m_dLow;
	double m_dHigh;
	double m_dOpen;
	double m_dClose;
public:
	Companies( std::string strName , std::string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: m_strName(strName) ,
	  m_strTicker(strTicker) ,
	  m_nDate(nDate) ,
	  m_dLow(dLow) ,
	  m_dHigh(dHigh) ,
	  m_dOpen(dOpen) ,
	  m_dClose(dClose)
	{

	}
	
	std::string GetName()					{ return m_strName; }
	
	std::string GetTicker()					{ return m_strTicker; }
	
	int GetDate()							{ return m_nDate; }
	
	double GetLow()							{ return m_dLow; }
	
	double GetHigh()						{ return m_dHigh; }

	double SetOpen()
	{
		
	}
	
	double GetOpen()						{ return m_dOpen; }
	
	double GetClose()						{ return m_dClose; }
	
	virtual const char* Analysis() = 0;
};

class Walmart: public Companies
{
public:
	Walmart( string strName , string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: Companies( strName , strTicker , nDate , dLow , dHigh , dOpen , dClose )
	{

	}
	virtual const char *Analysis()
	{
		return "Walmart is currently the number one Fortune 500 company.";
	}
};


class Exxon: public Companies
{
public:
	Exxon( string strName , string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: Companies( strName , strTicker , nDate , dLow , dHigh , dOpen , dClose )
	{

	}
	virtual const char *Analysis()
	{
		return "Exxon Mobil is currently the number two Fortune 500 company.";
	}

};


class Apple: public Companies
{
public:
	Apple( string strName , string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: Companies( strName , strTicker , nDate , dLow , dHigh , dOpen , dClose )
	{

	}
	virtual const char *Analysis()
	{
		return "Apple is currently the number five Fortune 500 company.";
	}
};



class GenMotors: public Companies
{
public:
	GenMotors( string strName , string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: Companies( strName , strTicker , nDate , dLow , dHigh , dOpen , dClose )
	{

	}
	virtual const char *Analysis()
	{
		return "General Motors is currently the number six Fortune 500 company.";
	}


};


class CVS: public Companies
{
public:
	CVS( string strName , string strTicker , int nDate , double dLow , double dHigh , double dOpen , double dClose )
	: Companies( strName , strTicker , nDate , dLow , dHigh , dOpen , dClose )
	{

	}
	virtual const char *Analysis()
	{
		return "CVS is currently the number ten Fortune 500 company.";
	}
};

void Fortune500( Companies &rCompany )
{
	cout << rCompany.Analysis() << endl;
}

//name , ticker , date , low , high , open , close

//walmart , exonn , apple , ge , cvs
int main()
{

	string myName("N/A");
	string myTicker("N/A");
	int myDate(0);
	double myLow(0.0);
	double myHigh(0.0);
	double myOpen(0.0);
	double myClose(0.0); 
	Walmart cWalmart(myName , myTicker , myDate , myLow , myHigh , myOpen , myClose );
	Exxon cExxon(myName , myTicker , myDate , myLow , myHigh , myOpen , myClose );
	Apple cApple(myName , myTicker , myDate , myLow , myHigh , myOpen , myClose );
	GenMotors cGM(myName , myTicker , myDate , myLow , myHigh , myOpen , myClose );
	CVS cCVS(myName , myTicker , myDate , myLow , myHigh , myOpen , myClose );
	cout << "About which company would you like to inquire?" << endl;
	unsigned int companyChoice(0);
	do 
	{
		cout << "1).Walmart" << endl;
		cout << "2).Exxon Mobile" << endl;
		cout << "3).Apple" << endl;
		cout << "4).General Electric" << endl;
		cout << "5).CVS" << endl;
		cout << "Enter number selection here: " ;
		cin >> companyChoice;

		
	} while( (companyChoice < 1) && (companyChoice > 5) );
	cout << endl;

	switch( companyChoice )
	{
		case 1:
		{
			Fortune500(cWalmart);
			break;
		}
		case 2:
		{
			Fortune500(cExxon);
			break;
		}
		case 3:
		{
			Fortune500(cApple);
			break;
		}
		case 4:
		{
			Fortune500(cGM);
			break;

		}
		case 5:
		{
			Fortune500(cCVS);
			break;
		}
		default:
		{
			cout << "LOL\n" << endl;
		}




			



	}
	cout << endl;



	return 0;
}









