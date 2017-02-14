/* 
 
This is a simple game of blackjack. The computer begins by randomly drawing
2 cards with values between either 1 - 10 and tallies the sum of all cards drawn.
If the player continues to play and the sum of all cards drawn is greater than 21, 
then the game is a bust and will be asked to play again. Otherwise, the player can 
continue to play until they reach 21 or bust or choose not to redraw.  A request to 
start a new game will be asked.

    Created by Stacey Rivet Beck on 1/30/17.
    Programming Fundamentals in C++
    David Lee Harden
 
    a2_1.cpp
*/

#include <iostream>
#include <cstdlib>  // library for rand and srand
#include <ctime>    // library for time function to generate random numbers
#include <string>

using namespace std;

int main()
{
    const int MIN_VALUE = 1;    // Min Card value as a constant
    const int MAX_VALUE = 10;   // Max Card value as a constant
    
    int cardOne;                //  Holds value of card one drawn
    int cardTwo;                //  Holds value of card two drawn
    int cardDraw;               //  Holds the value of the card re-drawn
    int total;                  //  Store the total value of all cards drawn
    string inputString;         //  Stores the string of yes or no questions
    bool fDrawAgain = false;    //  Is used in second do-while loop during call to play another card
    bool fBust = false;         //  Is used in if statement if total of card values is greater than 21
    bool fPlayAgain = false;    //  Is used in first do-while loop to play blackjack again
    
    // generating random numbers by seeding the numbers and getting the system time first (EXPLAIN MORE PG 129
    unsigned int seed = (unsigned int)(time(0));
    
    // Seeing random number generator
    srand(seed);
    
    // The first do-while loop that runs Play Again feature
    do
    {
    
        cout << "First Cards: ";                                            // Draws first cards from 1 - 10 and assigns the
        cardOne = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;       // random value to cardOne and cardTwo then adds
        cardTwo = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;       // each value to int total
        total += cardOne + cardTwo;
        
        cout << cardOne << ", ";
        cout << cardTwo << endl;
        cout << "Total: " << total << endl;
        
        
        //  Second do-while loop asking for the second card draw with an if statement
        //  if true then another card will be drawn at random from 1 - 10 and then added to
        //  the total as long as it is under 21, otherwise, bust
        do
        {
            cout << "Do you want another card? (y/n): ";
            cin >> inputString;
            
            if (inputString == "y" || inputString == "Y")
            {
                cout << "Card: ";
                cardDraw = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                
                cout << cardDraw << endl;
                total += cardDraw;
                cout << "Total: " << total << endl;
                
                if (total > 21)
                {
                    cout << "Bust" << endl;
                    fBust = true;
                }
                
                fDrawAgain = true;
            }
            else
            {
                fDrawAgain = false;
            }
        }
        while(fDrawAgain && !fBust);
        
        
        cout << "Would you Like to Play Again? (y/n): ";
        cin >> inputString;
        
        if (inputString == "y" || inputString == "Y")
        {
            total = 0;                                  //  resets total to start a new game
            fPlayAgain = true;                          //  resets fPlayAgain to true to run first do-while
            fBust = false;
        }
        else
        {
            fPlayAgain = false;
        }
        
    }
    while (fPlayAgain);
    
    
    return(0);

}
