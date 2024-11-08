//Is Multiple main

#include <iostream>
#include <iomanip>

using namespace std;

bool get_multiple(int num_1, int num_2)
{
    if((num_1 % num_2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int num1, num2;
    bool multiple;
    
    //get two integer numbers
    cout << "What is the first number? ";
    cin >> num1;
    
    cout << "What is the second number? ";
    cin >> num2;

    if (num1 > 0 && num2 > 0)
    {
        multiple = get_multiple(num1, num2);
        
        if (multiple)
        {
            cout << "\n" << num1 << " is a multiple of " << num2 << endl;
        }
        else
        {
            cout << "\n" << num1 << " is NOT a multiple of " << num2 << endl;
        }
    }
    else
    {
        cout << "\n*** Invalid input: one or both values is not positive" << endl;
    }

    return 0;

} // end main()
