//
//Arithmetic Daily
//

#include <iostream>
#include <iomanip>

using namespace std;

int add(int first_number, int second_number)
{
    int added_value;
    
    added_value = first_number + second_number;
    
    return added_value;
}

int subtract(int first_number, int second_number)
{
    int subtracted_value;
    
    subtracted_value = first_number - second_number;
    
    return subtracted_value;
}

int multiply(int first_number, int second_number)
{
    int multiplied_value;
    
    multiplied_value = first_number * second_number;
    
    return multiplied_value;
}

int divide(int first_number, int second_number)
{
    int divided_value;
    
    divided_value = first_number / second_number;
    
    return divided_value;
}

int remainder(int first_number, int second_number)
{
    int remainder_value;
    
    remainder_value = first_number % second_number;
    
    return remainder_value;
}

void display_results(int first_number, int second_number, int added_value, int subtracted_value_1, int subtracted_value_2, int multiplied_value, int divided_value_1, int divided_value_2, int remainder_value_1, int remainder_value_2)
{
    cout << "\n" << first_number << " + " << second_number << " = " << added_value << endl
    << first_number << " - " << second_number << " = " << subtracted_value_1 << endl
    << first_number << " * " << second_number << " = " << multiplied_value << endl
    << first_number << " / " << second_number << " = " << divided_value_1 << endl
    << first_number << " % " << second_number << " = " << remainder_value_1 << endl << endl
    << second_number << " - " << first_number << " = " << subtracted_value_2 << endl
    << second_number << " / " << first_number << " = " << divided_value_2 << endl
    << second_number << " % " << first_number << " = " << remainder_value_2 << "\n\n";
}

int main()
  {
    int num1, num2;
    int added_value;
    int subtracted_value_1;
    int subtracted_value_2;
    int multiplied_value;
    int divided_value_1;
    int divided_value_2;
    int remainder_value_1;
    int remainder_value_2;

    cout << "First number? ";
    cin >> num1;

    cout << "Second number? ";
    cin >> num2;

    added_value = add(num1, num2);
    subtracted_value_1 = subtract(num1, num2);
    subtracted_value_2 = subtract(num2, num1);
    multiplied_value = multiply(num1, num2);
    divided_value_1 = divide(num1, num2);
    divided_value_2 = divide(num2, num1);
    remainder_value_1 = remainder(num1, num2);
    remainder_value_2 = remainder(num2, num1);
    display_results(num1, num2, added_value, subtracted_value_1, subtracted_value_2, multiplied_value, divided_value_1, divided_value_2, remainder_value_1, remainder_value_2);


  return 0;
  }
