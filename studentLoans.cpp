STUDENT LOAN CALCULATOR 6/27/2015

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cassert>
#include "bankBools.h"
#include "bankConstants.h"
#include "fafsaBools.h"


int main()
{
    using namespace std;

    
    cout << "Enter principal amount borrowed: " ;
    cin >> principal;
    float originalPrincipal(principal);

    
    
    cout << "Enter days from now you would like to inquire about your balance: " ;
    cin >> daysPassed;
    
    cout << "Did you borrow from FAFSA, Bank, or other?: ";
    cin >> loanType;
    if ( loanType == "FAFSA" || loanType == "fafsa" || loanType == "Fafsa" )
    {
        cout << "\nAlright, great." << endl;
        
        cout << "Were any of those loans Direct Subsidized Loans? ";
        cin >> myDirectSub;
        
        //THIS IS WHERE THE YES OR NO FOR DIRECT LOAN CONFIRMATION COMES IN
        bool checkDirectUpperYes = isUpperYes(myDirectSub);
        bool checkDirectLowerYes = isLowerYes(myDirectSub);
        
        bool checkDirectUpperNo = isUpperNo(myDirectSub);
        bool checkDirectLowerNo = isLowerNo(myDirectSub);
        
//        cout << "\n" << checkDirectUpperYes << endl;
//        cout << "myDirectSub: " << myDirectSub << endl;
        //THIS IS WHERE THE YES OR NO FOR DIRECT LOAN CONFIRMATION STOPS
        
        if ( (checkDirectUpperYes) || (checkDirectLowerYes) )
        {
//            cout << "\nPlease enter 'Yes' to calculate a Direct Subsidized Loan or enter 'Nevermind' if you made a mistake. " << endl;
        
            cout << "If your loan was taken out between 7/1/13 and 6/30/14, please enter 1." << endl;
            cout << "If your loan was taken out between 7/1/11 and 6/30/13, please enter 2." << endl;
            cout << "If your loan was taken out between 7/1/10 and 6/30/11, please enter 3." << endl;
            cout << "Enter date option here: " ;
            int directSubDate;
            cin >> directSubDate;
            switch (directSubDate)
            {
                case 1:
                {//rate should be 3.86
                    cout << "\nYou borrowed this at a rate of 3.86%" << endl;
                    for ( int day(1) ; day <= daysPassed ; day++ )
                    {
                        totalOwed = .0386*(totalOwed + principal);
                        amt = ( principal * .0386 ) / 365.25;
                        principal = principal + amt;
                        
                        if ( day == daysPassed )
                            cout << "Your Direct Subsidized FAFSA loan total due is: $" << originalPrincipal + totalOwed << endl;
                        
                    }
                    break;
                }//end case 1 for loop
                case 2://rate should 3.40
                {
                    cout << "\nYou borrowed this at a rate of 3.40%" << endl;
                    for ( int day(1) ; day <= daysPassed ; day++ )
                    {
                        totalOwed = .0340*(totalOwed + principal);
                        amt = ( principal * .0340 ) / 365.25;
                        principal = principal + amt;
                        if ( day == daysPassed )
                            cout << "Your Direct Subsidized FAFSA loan total due is: $" << originalPrincipal + totalOwed << endl;
                    }
                    break;
                }//end case 2
                case 3://rate should 4.50
                {
                    cout << "\nYou borrowed this at a rate of 4.50%" << endl;
                    for ( int day(1) ; day <= daysPassed ; day++ )
                    {
                        totalOwed = .0450 * (totalOwed + principal);
                        amt = ( principal * .0450 ) / 365.25;
                        principal = principal + amt;
                        if ( day == daysPassed )
                            cout << "Your Direct Subsidized FAFSA loan total due is: $" << originalPrincipal + totalOwed << endl;
                    }
                    break;
                }//end case 3
            
            
            }//end switch (directSubDate)
        
        
        }// ends if ( loanType == "FAFSA") portion
        else if ( (checkDirectUpperNo) || (checkDirectLowerNo) )
        {
            cout << "Gotcha." << endl;
            cout << "Were any of your loans Direct Unsubsidized Loans? " ;
            cin >> myDirectUnsub;
            bool checkUnsubUpperYes = isUpperYes(myDirectUnsub);
            bool checkUnsubLowerYes = isLowerYes(myDirectUnsub);
            bool checkUnsubUpperNo = isUpperNo(myDirectUnsub);
            bool checkUnsubLowerNo = isLowerNo(myDirectUnsub);
            
            if ( (checkUnsubUpperYes) || (checkUnsubLowerYes) )
            {
                cout << "If your loan was taken out between 07/01/2016 and 06/30/2013, please enter 1." << endl;
                cout << "If your loan was taken out between 07/01/2013 and 06/30/2014, please enter 2." << endl;
                cout << "Enter date option here: " ;
                int directUnsubDate;
                cin >> directUnsubDate;
                switch (directUnsubDate)
                {
                    case 1: //Rate at 6.80%
                    {
                        cout << "\nYou borrowed this at a rate of 6.80%" << endl;
                        for ( int day(1) ; day <= daysPassed ; day++ )
                        {
                            totalOwed = .0680 * (totalOwed + principal);
                            amt = (principal * .0680 ) / 365.25;
                            principal = principal + amt;
                            if ( day == daysPassed )
                                cout << "Your Direct Unsubsidized loan total due is: $" << originalPrincipal + totalOwed << endl;
                        }
                        break;
                    }//ends case 1 for direct unsubsidized
                    
                    case 2: //Rate at 3.86%
                    {
                        cout << "\nYou borrowed this at a rate of 3.86%" << endl;
                        for ( int day(1) ; day <= daysPassed ; day++ )
                        {
                            totalOwed = .0386 * (totalOwed + principal);
                            amt = (principal * .0386 ) / 365.25;
                            principal = principal + amt;
                            if ( day == daysPassed )
                                cout << "Your Direct Unsubsidized loan total due is: $" << originalPrincipal + totalOwed << endl;
                        }
                        break;
                    }
                }// ends switch (directUnsubDate)
                
            } // ends if ( (checkUnsubUpperYes) || (checkUnsubLowerYes) )
            else if ( (checkUnsubUpperNo) || (checkUnsubLowerNo) )
            {
            
                cout << "\nSince you have confirmed for us that you have neither an Unsubsidized Direct Loan, nor a Subsidized Direct Loan, it will be assumed that you ergo have a Parent Plus Loan outstanding. " << endl;
                cout << "\nPlease enter 'yes' to confirm this: ";
                string confirmParentPlus;
                cin >> confirmParentPlus;
                bool checkUpperPlus = isUpperYes(confirmParentPlus);
                bool checkLowerPlus = isLowerYes(confirmParentPlus);
                cout << "\n" ;
                if ( (checkUpperPlus) || (checkLowerPlus) )
                {
                    cout << "If your loan was taken out between 07/01/2013 and 06/30/2014, please enter 1." << endl;
                    cout << "If your loan was taken out between 07/01/2006 and 07/01/2013, please enter 2." << endl;
                    cout << "Enter date option here: " ;
                    int parentPlusDate;
                    cin >> parentPlusDate;
                    
                    switch (parentPlusDate)
                    {
                        case 1: //rate at 6.41%
                        {
                            cout << "\nYou borrowed this at a rate of 6.41%" << endl;
                            for ( int day(1) ; day <= daysPassed ; day++ )
                            {
                                totalOwed = .0641 * (totalOwed + principal);
                                amt = (principal * .0641) / 365.25;
                                principal = principal + amt;
                                if ( day == daysPassed)
                                    cout << "Your Parent Plus loan total due is: $" << originalPrincipal + totalOwed << endl;
                            }
                            break;
                        }
                        case 2: //rate at 7.90%
                        {
                            cout << "\nYou borrowed this at a rate of 7.90%" << endl;
                            for ( int day(1) ; day <= daysPassed ; day++ )
                            {
                                totalOwed = .0790 * (totalOwed + principal);
                                amt = (principal * .0790) / 365.25;
                                principal = principal + amt;
                                if ( day == daysPassed)
                                    cout << "Your Parent Plus loan total due is: $" << originalPrincipal + totalOwed << endl;
                            }
                            break;
                        }//end of case 2
                    
                    
                    }//end of switch (parentPlusDate)
                
                
                }//end of if( (checkUpperPlus) || (checkLowerPlus) )
            
            
            } // end of else if ( (checkUnsubUpperNo) || (checkUnsubLowerNo) )
        
        
        } //( (checkDirectUpperYes) || (checkDirectLowerYes) )
    
    
    }// end of if ( loanType == "FAFSA" || loanType == "fafsa" || loanType == "Fafsa" )
    else if ( loanType == "Bank" || loanType == "bank" )
    {
        cout << "\nThanks.\n" << endl;
        
        cout << "Enter fixed interest rate of bank loan: " ;
        cin >> interestRatePercent;
        float interestRateDecimal(interestRatePercent/100);

        cout << "Here is a list of the five major private lending banks:\nPlease select from one of the following: " ;
        cout << "\n";
        cout << "1).Citizens Bank" << endl;
        cout << "2).Discover Student Loans" << endl;
        cout << "3).Pittsburgh National Corporation(PNC)" << endl;
        cout << "4).Wells Fargo" << endl;
        cout << "5).Other" << endl;
        bool checkCitizens;
        bool checkDiscover;
        bool checkPNC;
        bool checkWF;
        bool checkOther;
        do {
        cout << "Enter Bank Choice : " ;
//        cin.ignore();
        getline( cin , pickBank);
        cout << "\n";
        checkCitizens = isCitizensBank(pickBank);
        checkDiscover = isDiscoverBank(pickBank);
        checkPNC = isPNC(pickBank);
        checkWF = isWF(pickBank);
        checkOther = isOther(pickBank);
        } while ( checkCitizens == 0 && checkDiscover == 0 && checkPNC == 0 && checkWF == 0 && checkOther == 0);
//        cout << "citizens: " << checkCitizens << endl;
//        cout << "discover: " << checkDiscover << endl;
//        cout << "PNC: " << checkPNC << endl;
//        cout << "wf: " << checkWF << endl;
        if (checkCitizens)
        {
            cout << "You selected Citizens Bank." << endl;
            
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = interestRateDecimal * (totalOwed + principal);
                amt = ( principal * interestRateDecimal) / 365.25;
                principal = principal + amt;


                if ( day == daysPassed )
                    cout << "For a loan of $" << originalPrincipal << " and at an interest rate of " << interestRatePercent << "%, after " << daysPassed << " days, you will owe a total of $" << originalPrincipal + totalOwed << endl;
                
            }
            cout << "As a reference, Citizens Bank provides student loans at an interest rate ranging between 5.75% and 11.75%" << endl;
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .0575 * (totalOwed + principal);
                amt = ( principal * .0575 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The minimum amount you could owe, at 5.75%, is: $" << originalPrincipal + totalOwed << endl;
            }
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .1175 * (totalOwed + principal);
                amt = ( principal * .1175 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The maximum amount you could owe, at 11.75%, is: $" << originalPrincipal + totalOwed << endl;
            
            }// ends maximum for loop
        }//ends checkCitizens
        
        if (checkDiscover)
        {
            cout << "You selected Discover Bank." << endl;
            
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = interestRateDecimal * (totalOwed + principal);
                amt = ( principal * interestRateDecimal) / 365.25;
                principal = principal + amt;
                
                
                if ( day == daysPassed )
                    cout << "For a loan of $" << originalPrincipal << " and at an interest rate of " << interestRatePercent << "%, after " << daysPassed << " days, you will owe a total of $" << originalPrincipal + totalOwed << endl;
                
            }
            cout << "As a reference, Discover Student Loans provides loans at an interest rate ranging between 5.99% and 11.24%" << endl;
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .0599 * (totalOwed + principal);
                amt = ( principal * .0599 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The minimum amount you could owe, at 5.99%, is: $" << originalPrincipal + totalOwed << endl;
            }
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .1124 * (totalOwed + principal);
                amt = ( principal * .1124 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The maximum amount you could owe, at 11.24%, is: $" << originalPrincipal + totalOwed << endl;
                
            }// ends maximum for loop
        }//ends checkDiscover
        else if (checkPNC)
        {
            cout << "You selected PNC." << endl;
            
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = interestRateDecimal * (totalOwed + principal);
                amt = ( principal * interestRateDecimal) / 365.25;
                principal = principal + amt;
                
                
                if ( day == daysPassed )
                    cout << "For a loan of $" << originalPrincipal << " and at an interest rate of " << interestRatePercent << "%, after " << daysPassed << " days, you will owe a total of $" << originalPrincipal + totalOwed << endl;
                
            }
            cout << "As a reference, PNC Financial Services provides student loans at an interest rate ranging between 6.49% and 12.99%" << endl;
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .0649 * (totalOwed + principal);
                amt = ( principal * .0649 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The minimum amount you could owe, at 6.49%, is: $" << originalPrincipal + totalOwed << endl;
            }
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .1299 * (totalOwed + principal);
                amt = ( principal * .1299 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The maximum amount you could owe, at 12.99%, is: $" << originalPrincipal + totalOwed << endl;
                
            }// ends maximum for loop
        }//ends checkDiscover
        else if (checkWF)
        {
            cout << "You selected Wells Fargo." << endl;
            
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = interestRateDecimal * (totalOwed + principal);
                amt = ( principal * interestRateDecimal) / 365.25;
                principal = principal + amt;
                
                
                if ( day == daysPassed )
                    cout << "For a loan of $" << originalPrincipal << " and at an interest rate of " << interestRatePercent << "%, after " << daysPassed << " days, you will owe a total of $" << originalPrincipal + totalOwed << endl;
                
            }
            cout << "As a reference, Wells Fargo provides student loans at an interest rate ranging between 6.99% and 13.74%" << endl;
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .0699 * (totalOwed + principal);
                amt = ( principal * .0699 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The minimum amount you could owe, at 6.99%, is: $" << originalPrincipal + totalOwed << endl;
            }
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = .1374 * (totalOwed + principal);
                amt = ( principal * .1374 ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "The maximum amount you could owe, at 13.74%, is: $" << originalPrincipal + totalOwed << endl;
                
            }// ends maximum for loop
        }//ends checkDiscover
        else if (checkOther)
        {
            cout << "Enter interst rate: " ;
            float otherInterestRate;
            cin >> otherInterestRate;
            float originalOtherInterestRate(otherInterestRate);
            otherInterestRate = otherInterestRate / 100;
            for ( int day(1) ; day <= daysPassed ; day++ )
            {
                totalOwed = otherInterestRate * (totalOwed + principal);
                amt = ( principal * otherInterestRate ) / 365.25;
                principal = principal + amt;
                if ( day == daysPassed )
                    cout << "With a principal amount of $" << originalPrincipal << " and an interest rate of " << originalOtherInterestRate << "% you will owe $" << originalPrincipal + totalOwed << "  after " << daysPassed << " days." << endl;
            }
            
        }
    
    


    
            
            
            
            
                 
                
        
        
        
        
    
        
        
        
        
        
        
        
    
    
    
    
    
    
    }//ends else if ( loanType == "Bank" || loanType == "bank"  )
    
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}//end of int main()
