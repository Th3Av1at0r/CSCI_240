//
//  main.cpp
//  A6_functions
//
//  Created by Avi Schmookler on 3/5/24.
//

#include <iostream>
#include <iomanip>

using namespace std;

/*0===[============>
Function: addition

Use: This function calculates the sum of two integer values

Arguments: first_number - an integer that is used in the addition
           second_number - the second integer that is used in the addition
           sum - holds the sum of the two numbers

Returns: the sum of the two integer values

Note: None
<============]===0*/
int addition(int first_number, int second_number)
{
    int sum;
    
    sum = first_number + second_number;
    
    return sum;
}

/*0===[============>
Function: subtraction

Use: This function subtracts one integer from another

Arguments: first_number - starting integer
           second_number - the integer that will be subtracted from the first
           number - holds the number after subtraction

Returns: the total after subtraction

Note: None
<============]===0*/
int subtraction(int first_number, int second_number)
{
    int number;
    
    number = first_number - second_number;
    
    return number;
}

/*0===[============>
Function: multiplication

Use: This function calculates the sum of two integer values

Arguments: first_number - an integer that is used in the multiplication
           second_number - the second integer that is used in the multiplication
           total - holds the number after multiplication

Returns: the product of the two integer values

Note: None
<============]===0*/
int multiplication(int first_number, int second_number)
{
    int total;
    
    total = first_number * second_number;
    
    return total;
}

/*0===[============>
Function: quotient

Use: This function divides one integer by another

Arguments: first_number - starting integer
           second_number - the integer that will divide the first
           total - holds the number after division

Returns: the quotient

Note: None
<============]===0*/
int quotient(int first_number, int second_number)
{
    int total;
    
    total = first_number / second_number;
    
    return total;
}

/*0===[============>
Function: remaider

Use: This function divides one integer by another

Arguments: first_number - starting integer
           second_number - the integer that will divide the first
           remainder - holds the remainder calculated

Returns: the remainder

Note: None
<============]===0*/
int remainder(int first_number, int second_number)
{
    int remainder;
    
    remainder = first_number % second_number;
    
    return remainder;
}

/*0===[============>
Function: power

Use: This function multiplies an integer by itself another integer times

Arguments: first_number - starting integer
           second_number - the number of times to multiply by itself
           total - holds the total after each step

Returns: the total

Note: fun for loop
<============]===0*/
int power(int first_number, int second_number)
{
    int total = 1;
    int i;
    
    for (i = 0; i < second_number; i++)
    {
        total = total * first_number;
    }
    
    return total;
}

/*0===[============>
Function: factorial

Use: This function multiplies every whole number lower than the integer together

Arguments: number - the highest whole number
           total - holds the total after each step

Returns: the total

Note: fun for loop
<============]===0*/
int factorial(int number)
{
    int total = 1;
    int i;
    
    for (i = 0; i < number; i++)
    {
        total = total * (i + 1);
    }
    
    return total;
}

/*0===[============>
Function: get_value

Use: This function aquires a value from the user

Arguments: number - word for formatting sentence
           value - generic number holder

Returns: value

Note: None
<============]===0*/
int get_value(string number)
{
    int value;
    
    cout << "\nPlease enter the " << number << " value." << endl;
    cin >> value;
    
    return value;
}

/*0===[============>
Function: get_non_negative_value

Use: function that aquires a non-negative value from the user

Arguments: number - word for formatting sentence
           value - generic number holder
           valid - keeps track on if the inputted information is a valid response

Returns: value

Note: while loop untill valid
<============]===0*/
int get_non_negative_value(string number)
{
    int value = 0;
    bool valid = false;
    
    while (valid == false)
    {
        cout << "\nPlease enter the " << number << " non-negative value." << endl;
        cin >> value;
        
        if (value >= 0)
        {
            valid = true;
        }
        else
        {
            cout << "\n\nPlease enter a NON-NEGATIVE VALUE.";
        }
    }
    
    return value;
}

/*0===[============>
Function: get_non_zero_value

Use: function that aquires a non-zero value from the user

Arguments: number - word for formatting sentence
           value - generic number holder
           valid - keeps track on if the inputted information is a valid response

Returns: value

Note: while loop untill valid
<============]===0*/
int get_non_zero_value(string number)
{
    int value = 0;
    bool valid = false;
    
    while (valid == false)
    {
        cout << "\nPlease enter the " << number << " non-zero value." << endl;
        cin >> value;
        
        if (value >= 0)
        {
            valid = true;
        }
        else
        {
            cout << "\n\nPlease enter a NON-ZERO VALUE.";
        }
    }
    
    return value;
}

/*0===[============>
Function: menu

Use: function that aquires a command from the user

Arguments: operation - holds the command char value
           valid - keeps track on if the inputted information is a valid response

Returns: operation

Note: while loop untill valid
<============]===0*/
char menu()
{
    char operation = 'q';
    bool valid = false;
    
    while (valid == false)
    {
        cout << "What operation would you like to perform:" << endl
            << " + addition" << endl
            << " - subtraction" << endl
            << " * multiplication" << endl
            << " / division" << endl
            << " ^ number to power" << endl
            << " ! factorial" << endl
            << " q quit" << endl << endl
            << "Operation? ";
        cin >> operation;
        
        if(operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '^' && operation != '!' && operation != 'q')
        {
            cout << "\n\nThat is not a valid choice, please try again.";
        }
        else
        {
            valid = true;
        }
    }
    
    return operation;
}

/*0===[============>
Function: main

Use: function that spearheads the program

Arguments: operation - holds the command char value
           first_number - generic number holder for functions
           second_number - generic number holder for functions
           display_number - holds the number needed to display

Returns: 0

Note: switch case for what to do with the command recieved from menu
<============]===0*/
int main()
{
    char operation;
    int first_number;
    int second_number;
    int display_number;
    
    operation = menu();
    
    switch(operation)
    {
        case '+':
        {
            first_number = get_value("first");
            second_number = get_value("second");
            
            display_number = addition(first_number, second_number);
            
            cout << endl << first_number << " + " << second_number << " = " << display_number << endl << endl;
            
            break;
        }
        case '-':
        {
            first_number = get_value("first");
            second_number = get_value("second");
            
            display_number = subtraction(first_number, second_number);
            
            cout << endl << first_number << " - " << second_number << " = " << display_number << endl << endl;
            
            break;
        }
        case '*':
        {
            first_number = get_value("first");
            second_number = get_value("second");
            
            display_number = multiplication(first_number, second_number);
            
            cout << endl << first_number << " * " << second_number << " = " << display_number << endl << endl;
            
            break;
        }
        case '/':
        {
            first_number = get_value("dividend");
            second_number = get_non_zero_value("divisor");

            
            display_number = quotient(first_number, second_number);
            
            cout << endl << first_number << " / " << second_number << " = " << display_number << endl;
            
            display_number = remainder(first_number, second_number);
            
            cout << first_number << " % " << second_number << " = " << display_number << endl << endl;
            
            break;
        }
        case '^':
        {
            first_number = get_value("base");
            second_number = get_non_negative_value("power");
            
            display_number = power(first_number, second_number);
            
            cout << endl << first_number << " ^ " << second_number << " = " << display_number << endl << endl;
            
            break;
        }
        case '!':
        {
            first_number = get_non_negative_value("only");
            
            display_number = factorial(first_number);
            
            cout << endl << first_number << "! = " << display_number << endl << endl;
            
            break;
        }
        case 'q':
        {
            cout << endl << "Quitting." << endl;
            
            exit(0);
        }
        case 'Q':
        {
            cout << endl << "Quitting." << endl;
            
            exit(0);
        }
        default:
        {
            cout << endl << "That is an invalid operation!" << endl;
        }
    }
}
