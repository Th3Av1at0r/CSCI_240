/*0===[============>
CSCI 240         Program 8     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, April 5th

Purpose: implement a class called PiggyBank that will be used to represent a collection of coins. Functionality will be added to the class so that coins can be added to the bank and output operations can be performed.
<============]===0*/

#include <iostream>
#include <iomanip>

using namespace std;

//*************** Place the class description after this line ***************
/*0===[============>
Class: PiggyBank

Use: holds Pennies, Nickles, Dimes, and Quarters and functions around and with them

Note: fun making and using classes
<============]===0*/
class PiggyBank
{
private:
    int numPennies;
    int numNickles;
    int numDimes;
    int numQuarters;

public:
    PiggyBank();
    
    void printBank();
    void printBankValue();
    void emptyTheBank();
    void addCoins( int morePennies, int moreNickels, int moreDimes, int moreQuarters );
    void addPennies( int morePennies );
    void addNickels( int moreNickels );
    void addDimes( int moreDimes );
    void addQuarters( int moreQuarters );
    double calcBankValue();
};

//****************************************************************************

int main()
{
//Test 1 -- default constructor and printPiggyBank
cout << "***** Test 1: Default Constructor and printPiggyBank *****" << endl << endl;
cout << fixed << setprecision(2);

//create two objects using the default constructor
PiggyBank bank1;
PiggyBank bank2 = PiggyBank();

//display the two objects
cout << "bank1:" << endl;

bank1.printBank();

cout << endl << endl << "bank2:" << endl;

bank2.printBank();


//Test 2 -- printBankValue
cout << endl << endl << endl << "***** Test 2: printBankValue *****" << endl << endl
     << "bank1:" << endl;

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//Test 3 -- adding coins
cout << endl << endl << endl << "***** Test 3: addCoins Method *****" << endl << endl
     << "3a: Adding 2 pennies, 47 nickels, 20 dimes, and 5 quarters to bank1 produces:"
     << endl << endl;

//update bank 1: 2 pennies, 47 nickels, 20 dimes, and 5 quarters   and display
bank1.addCoins( 2, 47, 20, 5 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//update bank 2: 143 pennies, 9 nickels, 0 dimes, and 44 quarters   and display
bank2.addCoins( 143, 9, 0, 44 );

cout << endl << endl << "3b: Adding 143 pennies, 9 nickels, 0 dimes, and 44 quarters to bank2 produces:"
     << endl << endl;

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();


//Test 4 -- adding pennies
cout << endl << endl << endl << "***** Test 4: addPennies Method *****" << endl << endl
     << "4a: Adding 95 pennies to bank1:" << endl << endl;

//update bank 1: 95 pennies   and display
bank1.addPennies( 95 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


cout << endl << endl << "4b: Adding -54 pennies to bank1:" << endl << endl;

//(try to) update bank 1: -54 pennies   and display
bank1.addPennies( -54 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


//Test 5 -- adding nickels
cout << endl << endl << endl << "***** Test 5: addNickels Method *****" << endl << endl
     << "5a: Adding -12 nickels to bank2:" << endl << endl;

//(try to) update bank 2: -12 nickels   and display
bank2.addNickels( -12 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();


cout << endl << endl << "5b: Adding 17 nickels to bank2:" << endl << endl;

//update bank 2: 17 nickels   and display
bank2.addNickels(17);

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



//Test 6 -- adding dimes
cout << endl << endl << endl << "***** Test 6: addDimes Method *****" << endl << endl
     << "6a: Adding 157 dimes to bank2:" << endl << endl;

//update bank 2: 157 dimes   and display
bank2.addDimes( 157 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();

cout << endl << endl << "6b: Adding -37 dimes to bank2:" << endl << endl;

//(try to) update bank 2: -37 dimes   and display
bank2.addDimes( -37 );

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



//Test 7 -- adding quarters
cout << endl << endl << endl << "***** Test 7: addQuarters Method *****" << endl << endl
     << "7a: Adding 14 quarters to bank1: " << endl << endl;

//update bank 1: 14 quarters   and display
bank1.addQuarters( 14 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();


cout << endl << endl << "7b: Adding -45 quarters to bank1:" << endl << endl;

//(try to) update bank 1: -45 quarters   and display
bank1.addQuarters( -45 );

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();



//Test 8 -- bank value
cout << endl << endl << endl << "***** Test 8: Calculating the Bank Values *****" << endl << endl;

//Get the current value of both banks and calculate the total amount of money
double bank1value = bank1.calcBankValue(),
       bank2value = bank2.calcBankValue();

double total = bank1value + bank2value;

//display the calculated total
cout << "$" << bank1value << " + $" << bank2value << " = $" << total << endl << endl;


//Test 9 -- empty the bank
cout << endl << endl << endl << "***** Test 9: Emptying the PiggyBanks *****" << endl << endl
     << "It\'s time to empty the banks!" << endl << endl;

cout << endl << "9a: bank1 initially contains: " << endl << endl;

//display the current value of bank1 and the updated value after it has been emptied
bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();

bank1.emptyTheBank();

cout << endl << endl << "bank1 now contains: " << endl << endl;

bank1.printBank();

cout << endl << "Total: ";

bank1.printBankValue();



cout << endl << endl << endl << "9b: bank2 initially contains: " << endl << endl;

//display the current value of bank2 and the updated value after it has been emptied
bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();

bank2.emptyTheBank();

cout << endl << endl << "bank2 now contains: " << endl << endl;

bank2.printBank();

cout << endl << "Total: ";

bank2.printBankValue();



cout << endl << endl;

return 0;
}//end of int main()


//*************** Implement the class methods after this line ***************
//***************   DON'T FORGET TO ADD DOCUMENTATION BOXES   ***************


/*0===[============>
Function: PiggyBank

Use: Constructor to initiate the variable

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
PiggyBank::PiggyBank()
{
    emptyTheBank();
}

/*0===[============>
Function: printBank

Use: prints the values in Pennies, Nickles, Dimes, and Quarters

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void PiggyBank::printBank()
{
    cout << "| Pennies:\t" << numPennies
        << "\t| Niclkes:\t" << numNickles
        << "\t| Dimes:\t" << numDimes
        << "\t| Quarters:\t" << numQuarters << "\t|" << endl;
}

/*0===[============>
Function: printBankValue

Use: prints the total calculated in calcBankValue

Arguments: total - Holds the total to be printed

Returns: nothing

Note:
<============]===0*/
void PiggyBank::printBankValue()
{
    double total;
    
    total = calcBankValue();
    
    cout << fixed << setprecision(2) << "$" << total << endl;
}

/*0===[============>
Function: emptyTheBank

Use: sets all coin variables in a PiggyBank class variable to 0

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void PiggyBank::emptyTheBank()
{
    numPennies = 0;
    numNickles = 0;
    numDimes = 0;
    numQuarters = 0;
}

/*0===[============>
Function: addCoins

Use: Streamlines adding multiple types of coins at once

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void PiggyBank::addCoins( int morePennies, int moreNickels, int moreDimes, int moreQuarters )
{
    addPennies(morePennies);
    addNickels(moreNickels);
    addDimes(moreDimes);
    addQuarters(moreQuarters);
}

/*0===[============>
Function: ALL ADD COIN FUNCTIONS

Use: adds the int of specified coin to the coin total

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void PiggyBank::addPennies( int morePennies )
{
    if (morePennies < 0)
    {
        cout << "Error 1: atempting to add negative pennies." << endl;
    }
    else
    {
        numPennies += morePennies;
    }
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
void PiggyBank::addNickels( int moreNickels )
{
    if (moreNickels < 0)
    {
        cout << "Error 1: atempting to add negative nickles." << endl;
    }
    else
    {
        numNickles += moreNickels;
    }
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
void PiggyBank::addDimes( int moreDimes )
{
    if (moreDimes < 0)
    {
        cout << "Error 1: atempting to add negative Dimes." << endl;
    }
    else
    {
        numDimes += moreDimes;
    }
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
void PiggyBank::addQuarters( int moreQuarters )
{
    if (moreQuarters < 0)
    {
        cout << "Error 1: atempting to add negative quarters." << endl;
    }
    else
    {
        numQuarters += moreQuarters;
    }
}

/*0===[============>
Function: calcBankValue

Use: calculates the dollar ammount with the coins in the bank

Arguments: total - gets all dollar ammounts added to it

Returns: total

Note:
<============]===0*/
double PiggyBank::calcBankValue()
{
    double total;
    
    total = (numPennies * .01);
    total += (numNickles * .05);
    total += (numDimes * .1);
    total += (numQuarters * .25);
    
    return total;
}
