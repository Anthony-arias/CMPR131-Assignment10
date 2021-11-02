// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 10:
// 10/14/2021


#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"

void displayMainMenu(void);
void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);
void displayOptionTwoMenu(void);
void displayOptionThreeMenu(void);


using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: return;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: 
void programOne(void)
{
    clearScreen();
    cout << "\t1> Tree of strings" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    /*stuff here*/
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    do
    {
        clearScreen();
        cout << "\t2> bTree container" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        displayOptionTwoMenu();

        int userInput = inputChar("\t\tOption: ");
        switch (userInput)
        {
        case '0': return;
        case 'a': case 'A': /*Function here*/ break;
        case 'b': case 'B': /*Function here*/ break;
        case 'c': case 'C': /*Function here*/ break;
        case 'd': case 'D': /*Function here*/ break;
        case 'e': case 'E': /*Function here*/ break;
        case 'f': case 'F': /*Function here*/ break;
        case 'g': case 'G': /*Function here*/ break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D','E','F', or 'G'" << endl; pause("");
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: 
void programThree(void)
{   
    do
    {
        clearScreen();
        cout << "\t3> Animal Guessing Game" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        displayOptionThreeMenu();

        int userInput = inputChar("\t\tOption: ");
        switch (userInput)
        {
        case '0': return;
        case 'a': case 'A': /*Function here*/ break;
        case 'b': case 'B': /*Function here*/ break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B'" << endl; pause("");
        }

    } while (true);
    
}


//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 10: Trees by Anthony, An, Van, Vincent, Nhan (10/21/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Tree of strings" << endl;
    cout << "\t\t2> Tree container of integers" << endl;
    cout << "\t\t3> Animal Guessing Game" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition:
void displayOptionTwoMenu(void)
{
    cout << "\t\tA> Insert a node/leaf" << endl;
    cout << "\t\tB> Count of Nodes/leaves" << endl;
    cout << "\t\tC> Search a node/leaf" << endl;
    cout << "\t\tD> Pre-order traversal" << endl;
    cout << "\t\tE> In-order traversal" << endl;
    cout << "\t\tF> Post-order traveral" << endl;
    cout << "\t\tG> Delete the entire tree" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition:
void displayOptionThreeMenu(void)
{
    cout << "\n\tA game tree for a simple game of ""animal"" twenty questions would look like:" << endl;
    cout << "\t                                 [ Is it a mammal? ]" << endl;
    cout << "\t                                     /         \\" << endl;
    cout << "\t                                    /           \\" << endl;
    cout << "\t                [ Does it have stripes? ]     [ Is it a bird? ]" << endl;
    cout << "\t                      /       \\                  /       \\" << endl;
    cout << "\t                     /         \\                /         \\" << endl;
    cout << "\t                ( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )" << endl;
    cout << "\t                                           /       \\" << endl;
    cout << "\t                                          /         \\" << endl;
    cout << "\t                                    ( Eagle )     ( Penguin )" << endl;
    cout << "\tA learning version of twenty questions: one that not only plays the game, but learns new" << endl;
    cout << "\tobjects when it loses." << endl;
    cout << "\n\tWelcome to Animal Guessing Game" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Play the game" << endl;
    cout << "\t\tB> Save the game file" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}
