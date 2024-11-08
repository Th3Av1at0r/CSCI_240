//CSCI 240 daily - Reverse Number

#include <iostream>
#include <iomanip>

using namespace std;

void display_reverse_number(int N)
{
    int reversed_number = 0;
    int remainder;
    
    while(N != 0)
    {
        remainder = N % 10;
        cout << reversed_number * 10 + remainder;
        N /= 10;
    }
    
    cout << endl;
}

void display(int N)
{
    cout << "\nOriginal: " << N << endl
    << "Reversed: ";
}

int main()
{
    int N;
    bool valid = false;
    
    cout << "N value (must be positive)? ";
    cin >> N;
  
    while (valid == false)
    {
        if(N <= 0)
        {
            cout << "Error: the N-value must be positive. Try again: ";
            cin >> N;
        }
        else
        {
            valid = true;
        }
    }
    
    display(N);
    display_reverse_number(N);

    return 0;
}
