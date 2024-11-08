/*0===[============>
CSCI 240         Program 9     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, April 5th

Purpose: build on the PiggyBank class by adding some additional methods and constructors. A regular function (i.e. not part of the PiggyBank class) should also be added.
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
    PiggyBank(int, int, int, int);
    PiggyBank(const PiggyBank&);
    
    void print(string);
    void printBank();
    void printBankValue();
    void emptyTheBank();
    PiggyBank addBanks(int, int, int, int);
    PiggyBank addBanks(PiggyBank);
    bool isEqual(int, int, int, int);
    bool isEqual(PiggyBank otherBank);
    bool isLessThan(int, int, int, int);
    bool isLessThan(PiggyBank otherBank);
    int getCoin(int);
    void addCoins( int morePennies, int moreNickels, int moreDimes, int moreQuarters );
    void addPennies( int morePennies );
    void addNickels( int moreNickels );
    void addDimes( int moreDimes );
    void addQuarters( int moreQuarters );
    double calcBankValue();
};

void printSectionTitle(string);

//****************************************************************************

int main()
{
    PiggyBank bank_1(12, 34, 56, 78);
    PiggyBank bank_2(23, -5, -10, 31);
    PiggyBank bank_3(bank_1);
    
    printSectionTitle("Initial values in the bank objects");
    bank_1.print("\nInitial bank_1 value:");
    bank_2.print("\nInitial bank_2 value:");
    bank_3.print("\nInitial bank_3 value:");
    printSectionTitle("Using the addBanks method with 4 arguments");
    PiggyBank bank_4;
    bank_4.print("\nInitial bank_4 value:");
    bank_4 = bank_2.addBanks(4, 27, 45, 7);
    bank_2.print("\nbank_2 value after:");
    bank_4.print("\nbank_4 value after:");
    printSectionTitle("Using the addBanks method with PiggyBank object");
    PiggyBank bank_5;
    bank_1.print("\nInitial bank_1 value:");
    bank_2.print("\nInitial bank_2 value:");
    bank_5.print("\nInitial bank_5 value:");
    bank_5 = bank_1.addBanks(bank_2);
    bank_1.print("\nbank_1 after:");
    bank_2.print("\nbank_2 after:");
    bank_5.print("\nbank_5 after:");
    printSectionTitle("Using the isEqual method with 4 arguments");
    
    cout << "\nTest result with bank_4 is: ";
    
    if(bank_4.isEqual(27, 27, 45, 38))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    
    cout << "\nTest result with bank_5 is: ";
    
    if(bank_5.isEqual(35, 34, 15, 7))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    
    printSectionTitle("Using the isEqual method with PiggyBank object");
    
    cout << "\nTest result with bank_5 and bank_2 is: ";
    
    if(bank_5.isEqual(bank_2))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    
    cout << "\nTest result with bank_1 and bank_3 is: ";
    
    if(bank_1.isEqual(bank_3))
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    
    printSectionTitle("Current values in the bank objects");
    bank_1.print("bank_1");
    bank_2.print("bank_2");
    bank_3.print("bank_3");
    bank_4.print("bank_4");
    bank_5.print("bank_5");
    printSectionTitle("Using the isLessThan method with 4 arguments");
    
    cout << "\nbank_1 is: ";
    
    if(bank_1.isLessThan(12, 33, 42, 108))
    {
        cout << "less than the other" << endl;
    }
    else
    {
        cout << "Not less than the other" << endl;
    }
    
    cout << "\nbank_2 is: ";
    
    if(bank_2.isLessThan(3, 4, 70, 3))
    {
        cout << "less than the other" << endl;
    }
    else
    {
        cout << "Not less than the other" << endl;
    }
    
    printSectionTitle("Using the isLessThan method with PiggyBank object");
    
    cout << "\nbank_3 is: ";
    
    if(bank_3.isLessThan(bank_5))
    {
        cout << "less than bank_5" << endl;
    }
    else
    {
        cout << "Not less than bank_5" << endl;
    }
    
    cout << "\nbank_4 is: ";
    
    if(bank_4.isLessThan(bank_2))
    {
        cout << "less than bank_2" << endl;
    }
    else
    {
        cout << "Not less than bank_2" << endl;
    }
    
    printSectionTitle("Using the getCoin method");
    
    cout << "\nThe number of pennies in bank_1 is " << bank_1.getCoin(0) << "." << endl
        << "\nThe number of nickles in bank_2 is " << bank_2.getCoin(1) << "." << endl
        << "\nThe number of dimes in bank_3 is " << bank_3.getCoin(2) << "." << endl
        << "\nThe number of quarters in bank_4 is " << bank_4.getCoin(3) << "." << endl
        << "\nThe number of ERROR in bank_5 is " << bank_5.getCoin(4) << "." << endl << endl;

    return 0;
}//end of int main()


//*************** Implement the class methods after this line ***************
//***************   DON'T FORGET TO ADD DOCUMENTATION BOXES   ***************


/*0===[============>
Function: PiggyBank

Use: Constructor to initiate the variables in the bank to 0, a number, or a copy

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
PiggyBank::PiggyBank()
{
    emptyTheBank();
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
PiggyBank::PiggyBank(int pennies, int nickles, int dimes, int quarters)
{
    emptyTheBank();
    addCoins(pennies, nickles, dimes, quarters);
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
PiggyBank::PiggyBank(const PiggyBank& otherBank)
{
    emptyTheBank();
    addCoins(otherBank.numPennies, otherBank.numNickles, otherBank.numDimes, otherBank.numQuarters);
}

/*0===[============>
Function: print

Use: prints a message then the number of each coin and the total

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void PiggyBank::print(string message)
{
    cout << message << endl;
    
    printBank();
    printBankValue();
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
Function: addBanks

Use: adds two banks to eachother and returns a new bank with the total

Arguments: bank_sum - new bank, sum of other two

Returns: bank_sum

Note:
<============]===0*/

PiggyBank PiggyBank::addBanks(int pennies, int nickles, int dimes, int quarters)
{
    PiggyBank bank_sum(pennies + numPennies, nickles + numNickles, dimes + numDimes, quarters + numQuarters);
    
    return bank_sum;
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
PiggyBank PiggyBank::addBanks(PiggyBank otherBank)
{
    PiggyBank bank_sum;
    
    bank_sum = otherBank.addBanks(numPennies, numNickles, numDimes, numQuarters);
    
    return bank_sum;
}

/*0===[============>
Function: isEqual

Use: checks to see if banks are equal

Arguments: is_equal - true if equal
           temp_bank - bank to send into calcBankValue

Returns: is_equal

Note:
<============]===0*/

bool PiggyBank::isEqual(int pennies, int nickles, int dimes, int quarters)
{
    bool is_equal = false;
    PiggyBank temp_bank(pennies, nickles, dimes, quarters);
    
    if (temp_bank.calcBankValue() == calcBankValue())
    {
        is_equal = true;
    }
    
    return is_equal;
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
bool PiggyBank::isEqual(PiggyBank otherBank)
{
    bool is_equal = false;
    
    is_equal = otherBank.isEqual(numPennies, numNickles, numDimes, numQuarters);
    
    return is_equal;
}

/*0===[============>
Function: isLessThan

Use:checks to see if a bank is less than another

Arguments: is_less_than - true if less than
           temp_bank - bank to send into calcBankValue

Returns: is_less_than

Note:
<============]===0*/
bool PiggyBank::isLessThan(int pennies, int nickles, int dimes, int quarters)
{
    bool is_less_than = false;
    
    PiggyBank temp_bank(pennies, nickles, dimes, quarters);
    
    if (temp_bank.calcBankValue() > calcBankValue())
    {
        is_less_than = true;
    }
    
    return is_less_than;
}

/*0===[============>

 SEE ABOVE
 
<============]===0*/
bool PiggyBank::isLessThan(PiggyBank otherBank)
{
    bool is_less_than;
    
    is_less_than = otherBank.isLessThan(numPennies, numNickles, numDimes, numQuarters);
    
    if(is_less_than == true)
    {
        is_less_than = false;
    }
    else
    {
        is_less_than = true;
    }
    
    return is_less_than;
}

/*0===[============>
Function: getCoin

Use: accessor method for coins

Arguments: N/A

Returns: number of type of coin or -1 if not in index.

Note:
<============]===0*/
int PiggyBank::getCoin(int coinIndex)
{
    switch(coinIndex)
    {
        case 0:
            
            return numPennies;
            
        case 1:
            
            return numNickles;
            
        case 2:
            
            return numDimes;
            
        case 3:
            
            return numQuarters;
            
        default:
            
            return -1;
            
    }
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

/*0===[============>
Function: printSectionTitle

Use: prints a line splitting the output from the rest

Arguments: N/A

Returns: Nothing

Note:
<============]===0*/
void printSectionTitle(string title)
{
    cout << "\n\n0===[=========================> <=========================]===0" << endl
        << title << endl;
}
