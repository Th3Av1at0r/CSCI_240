//Is Even Odd daily
#include <iostream>
#include <iomanip>

using namespace std;

int main()
  {
    int num;
    bool valid = false;

    //get a number from the user
    cout << "Enter an integer value: ";
    cin >> num;
    
    while (valid != true)
    {
        if (num == 0)
        {
            cout << "The value cannot be 0.";
            
            exit(0);
        }
        else
        {
            valid = true;
        }
    }
    
    if (num % 2 == 0)
    {
        cout << endl << "The value " << num << "is EVEN." << endl;
    }
    else
    {
        cout << endl <<"The value " << num << "is ODD." << endl;
    }
    
    return 0;
  }
