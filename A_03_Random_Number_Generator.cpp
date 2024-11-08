/*0===[============>
CSCI 240         Program 3     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, February 16

Purpose: Generate three sets of random numbers.
<============]===0*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void first_random_set(int line_split)
{
    int number;
    const int number_of_values = 45;
    int number_of_odds = 0;
    
    
    cout << "0===[============> First Set (45 values)" << endl;
    
//    for loop that generates and displays random numbers
    for (int i = 0; i < number_of_values; i++)
    {
//        assigns a random generated int with no limit to number
        number = rand();
        
        cout << setw(15) << number << " ";
        
        if ((i + 1) % line_split == 0)
        {
            cout << endl;
        }
        
//        checks if the generated number is odd, if so it adds to the count
        if (number % 2 == 1)
        {
            number_of_odds++;
        }
        
    }
    
    cout << endl << "0===[============> This set had " << number_of_odds << " odd numbers."
        << endl << endl << endl;
}

void second_random_set(int number_of_values, int line_split)
{
    int i = 0;
    int number;
    int number_of_evens = 0;
    
    cout << "0===[============> Second Set (" << number_of_values << " values)" << endl;
    
//    while loop that generates and displays random numbers
    while (i < number_of_values)
    {
//        assigns a random generated int with no limit to number
        number = rand();
        
        cout << setw(15) << number << " ";
        
        if ((i + 1) % line_split == 0)
        {
            cout << endl;
        }
        
//        checks if the generated number is even, if so it adds to the count
        if (number % 2 == 0)
        {
            number_of_evens++;
        }
        
        i++;
    }
    
    cout << endl << "0===[============> This set had " << number_of_evens << " even numbers."
        << endl << endl << endl;
}

void third_random_set(int number_of_values, int line_split)
{
    int i = 0;
    int over_two_hundred = 0;
    double number;
    const double minimum_value = 0.0;
    const double maximum_value = 300.0;
    
    cout << "0===[============> Third Set (" << number_of_values << " values)" << endl;
    
//    do while loop that generates and displays random numbers
    do
    {
//        assigns a random generated double between 0.0 and 300.0 to number
        number = minimum_value + (rand() / (RAND_MAX / (maximum_value - minimum_value)));
        
        cout << setw(15) << fixed << setprecision(1) << number << " ";
        
        if ((i + 1) % line_split == 0)
        {
            cout << endl;
        }
        
        if (number > 200.0)
        {
            over_two_hundred++;
        }
        
        i++;
    }
    while (i < number_of_values);
    
    cout << endl << "0===[============> This set had " << over_two_hundred
        << " numbers over 200.0." << endl << endl << endl;
}

int main() 
{
    srand(33);
    const int maximum_for_second_set = 75;
    const int maximum_for_third_set = 50;
    const int line_split = 7;
    
    first_random_set(line_split);
    second_random_set((rand() % maximum_for_second_set) + 1, line_split);
    third_random_set((rand() % maximum_for_third_set) + 1, line_split);

    return 0;
}
