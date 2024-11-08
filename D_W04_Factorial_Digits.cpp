// 240 Count Factorial Digits Daily

#include <iostream>
#include <iomanip>

using namespace std;

int calculate_factorial(int N)
{
    int factorial = 1;
    int i;
    
    for (i = 0; i < N; i++)
    {
        factorial = factorial * (i + 1);
    }
    
    return factorial;
}

void display_results(int N, int factorial, int number_of_digits)
{
    cout << "\n" << N << "! is equal to " << factorial << ". There are " << number_of_digits  << " digits." << endl;
}

int calculate_number_of_digits(int factorial)
{
    if (factorial == 0)
        return 1;
    int number_of_digits = 0;
    while (factorial != 0) {
        factorial = factorial / 10;
        number_of_digits++;
    }
    
    return number_of_digits;
}

int main()
{
    int N;
    int factorial;
    int number_of_digits;

    //Get the value for N
    cout << "N value (must be greater than or equal to 0)? ";
    cin >> N;
  
    if (N > 12 || N < 0)
    {
        cout << "\nInvalid Input: " << N << endl;
        
        exit(0);
    }
    factorial = calculate_factorial(N);
    number_of_digits = calculate_number_of_digits(factorial);
    display_results(N, factorial, number_of_digits);
    
    return 0;
} // end main()
