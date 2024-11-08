//
//  main.cpp
//  D2_sales_format
//
//  Created by Avi Schmookler on 1/30/24.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {

    double price;
    int number_of_items;
    double total;
    
    cout << "What is the price for a single item? ";
    cin >> price;
    cout << "How many items were purchased? ";
    cin >> number_of_items;
    
    total = price * number_of_items;
    
    cout  << fixed << setprecision(2) << setw(5) << right  << endl << number_of_items;
    cout << " items at $" << price << " each will cost $" << total << endl;
    
    return 0;
}
