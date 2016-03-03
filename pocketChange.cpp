#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cassert>
#include <time.h>


class Cents
{
private:
    int m_nCents;
public:
    Cents(int nCents) { m_nCents = nCents; }
    
    friend Cents operator + (const Cents &c1 , const Cents &c2);
    friend Cents operator - (const Cents &c1 , const Cents &c2);
    
    int GetCents() { return m_nCents;}
};
Cents operator + (const Cents &c1 , const Cents &c2)
{
    return Cents(c1.m_nCents + c2.m_nCents);
}
Cents operator - (const Cents &c1 , const Cents &c2)
{
    return Cents(c1.m_nCents - c2.m_nCents);
}


int main()
{
    using namespace std;
    int x , y;
    cout << "Enter change in right pocket: " ;
    cin >> x;
    cout << "Enter change in left pocket: " ;
    cin >> y;
    
//    cin >> cCents1;
    Cents cCents1(x);
    Cents cCents2(y);
    Cents cSum(cCents1 + cCents2);
    Cents cDiffRight(cCents1 - cCents2);
    Cents cDiffLeft(cCents2 - cCents1);
    
    
    string pocketChange;
    cout << "Woud you like the 'sum of' or the 'difference between' the change in your pockets? ";
    cin.ignore();
    getline( cin , pocketChange );
    
    cout << "\n" << endl;
    if (pocketChange == "sum of" || pocketChange == "sum of " || pocketChange == " sum of")
    {
        cout << "The sum of the change in your right pocket and left pocket totals: " << cSum.GetCents() << endl;
    }
    else if (pocketChange == "difference between")
    {
        if ( x > y )
        {
            cout << "The difference between the change in your right pocket and change in your left pocket is: " << cDiffRight.GetCents() << endl;
        }
        else if ( x < y)
        {
            cout << "The difference between the change in your left pocket and change in your right pocket is: " << cDiffLeft.GetCents() << endl;
        }
    }
    
  