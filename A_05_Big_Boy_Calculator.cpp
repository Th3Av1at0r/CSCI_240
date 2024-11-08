//
//  main.cpp
//  A5_big_boy_calculator
//
//  Created by Avi Schmookler on 2/20/24.
//

#include <iostream>
#include <iomanip>

using namespace std;

// function that adds 2 numbers
int addition(int first_number, int second_number)
{
    int sum;
    
    sum = first_number + second_number;
    
    return sum;
}

// function that subtracts a number from a number
int subtraction(int first_number, int second_number)
{
    int number;
    
    number = first_number - second_number;
    
    return number;
}

// function that multiplies 2 numbers
int multiplication(int first_number, int second_number)
{
    int total;
    
    total = first_number * second_number;
    
    return total;
}

// function that divides a number from another
int quotient(int first_number, int second_number)
{
    int total;
    
    total = first_number / second_number;
    
    return total;
}

// function that finds the remainder when two numbers are divided
int remainder(int first_number, int second_number)
{
    int remainder;
    
    remainder = first_number % second_number;
    
    return remainder;
}

// function that calculates a number to the power of another
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

// function that calculates the factorial of a number
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

int main()
{
    char operation;
    int first_number;
    int second_number;
    int display_number;
    
    while (true == true)
    {
        //    displays options
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
            
        //    changes what to do based on what the char operation is
        //    asks for the numbers then calls a function to calculate then prints
            switch(operation)
            {
                case '+':
                {
                    cout << endl << "What is the first number to add? ";
                    cin >> first_number;
                    cout << endl << "What is the second number to add? ";
                    cin >> second_number;
                    
                    display_number = addition(first_number, second_number);
                    
                    cout << endl << first_number << " + " << second_number << " = " << display_number << endl << endl;
                    
                    break;
                }
                case '-':
                {
                    cout << endl << "What is the first number to subtract? ";
                    cin >> first_number;
                    cout << endl << "What is the second number to subtract? ";
                    cin >> second_number;
                    
                    display_number = subtraction(first_number, second_number);
                    
                    cout << endl << first_number << " - " << second_number << " = " << display_number << endl << endl;
                    
                    break;
                }
                case '*':
                {
                    cout << endl << "What is the first number to multiply? ";
                    cin >> first_number;
                    cout << endl << "What is the second number to multiply? ";
                    cin >> second_number;
                    
                    display_number = multiplication(first_number, second_number);
                    
                    cout << endl << first_number << " * " << second_number << " = " << display_number << endl << endl;
                    
                    break;
                }
                case '/':
                {
                    cout << endl << "What is the dividend? ";
                    cin >> first_number;
                    cout << endl << "What is the divisor? ";
                    cin >> second_number;
                    
                    display_number = quotient(first_number, second_number);
                    
                    cout << endl << first_number << " / " << second_number << " = " << display_number << endl;
                    
                    display_number = remainder(first_number, second_number);
                    
                    cout << first_number << " % " << second_number << " = " << display_number << endl << endl;
                    
                    break;
                }
                case '^':
                {
                    cout << endl << "What is the base number? ";
                    cin >> first_number;
                    cout << endl << "What is the power? ";
                    cin >> second_number;
                    
                    display_number = power(first_number, second_number);
                    
                    cout << endl << first_number << " ^ " << second_number << " = " << display_number << endl << endl;
                    
                    break;
                }
                case '!':
                {
                    cout << endl << "What is the number? ";
                    cin >> first_number;
                    
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

    return 0;
}
