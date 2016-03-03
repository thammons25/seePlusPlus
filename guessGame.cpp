
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cassert>
#include <time.h>

int makeItNasty( int incomingNum)
{
    int seedNum(0);
    srand(incomingNum);
    for ( int i(1) ; i < incomingNum ; i++ )
    {
        seedNum = rand();
        seedNum = seedNum / i;
        seedNum = sqrt(seedNum*2);
        seedNum += seedNum;
        seedNum = sqrt(seedNum);
        
    }

    return(seedNum);
}
void printRandom( int randomNumberIn )
{
    using namespace std;
    
    
}

int main()
{
    using namespace std;
    int myGuess(0);
    cout << "Enter number: " ;
    int userNum;
    cin >> userNum;
    int computerNum(0);
    computerNum = makeItNasty(userNum);
    
    cout << "I'm thinking of a number. Can you guess what it is? " << endl;
    do
    {
        cout << "Enter guess: " ;
        cin >> myGuess;
        if (myGuess > computerNum)
            cout << "Your guess was too high!" << endl;
        else if (myGuess < computerNum)
            cout << "Your guess was too low!" << endl;
    } while ( myGuess != computerNum );
    cout << endl;
    cout << "Correct!" << endl;
    cout << "The number I was thinking of was: " << computerNum;
    
        
    
    
    
    
   
    
    
    
    
    
    
    
    return 0;

    
    
    
    
    
    
    
    
    
    
}
