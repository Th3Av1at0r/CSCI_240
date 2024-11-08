/*
Sum Values Between Boundary Daily
*/

#include <iostream>
#include <iomanip>

using namespace std;

int calculate_sum(int lower, int upper)
{
    int sum = 0;
    int i;
    
    for (i = lower; i <= upper; i++)
    {
        sum = sum + i;
    }
    
    return sum;
}

void display_results(int lower, int upper, int sum)
{
    cout << "\nThe sum of the values between " << lower << " and " << upper << " is " << sum << endl;
}

int main()
{
    int lower;
    int upper;
    int sum;
    int temp;

    //Get the lower and upper bounds
    cout << "What is the lower bound? ";
    cin >> lower;

    cout << "What is the upper bound? ";
    cin >> upper;
    
    if(lower > upper)
    {
        temp = lower;
        lower = upper;
        upper = temp;
        
        cout << "\n*** boundary values have been swapped ***" << endl;
    }
    
    sum = calculate_sum(lower, upper);
    display_results(lower, upper, sum);

    return 0;
}
