//240 Count daily int main()

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int N;
    bool valid = false;
    int i;
    
    cout << "N value (must be greater than or equal to 1)? ";
    cin >> N;
    
    while (valid != true)
    {
        if (N < 1)
        {
            cout << "Error: the N-value must be greater than or equal to 1. Try again: ";
            cin >> N;
            
            
            continue;
        }
        else
        {
            valid = true;
        }
    }
    
    cout << endl;
    
    for (i = 0; i < N; i++)
    {
        cout << i + 1 << endl;
    }
    
    return 0;
} // end main()
