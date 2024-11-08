/*0===[============>
CSCI 240         Program 7     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, March 29

Purpose: write a program that will read two sets of data representing a series of numeric measurements.
 The program will display the data, first unsorted and then sorted, and then compute and display various statistics about each of the data sets.
 In addition, the program will compute and display the differences between the statistics for the two sets of data.
<============]===0*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define end_character -999.99
#define max_size 20
#define line_length 8

int build_array(string, double[]);

void print_array(string, int, double[]);

void sort_array(double[], int);

double mean(double[], int);

double median(double[], int);

double low(double[], int);

double high(double[], int);

double standard_deviation(double[], int);

void display_differences(double, double, double, double, double, double);

/*0===[============>
Function: main

Use: function that spearheads the program

Arguments: array_A - first array
           array_B - second array
           array_A_size - size of the first array
           array_B_size - size of the Second array
           mean_A - stores the mean for the differences
           median_A - stores the median for the differences
           low_A - stores the low for the differences
           high_A - stores the high for the differences
           standard_deviation_A - stores the standard deviation for the differences
           mean_B - stores the mean for the differences
           median_B - stores the median for the differences
           low_B - stores the low for the differences
           high_B - stores the high for the differences
           standard_deviation_B - stores the standard deviation for the differences

Returns: 0

Note:
<============]===0*/
int main() {
    
    double array_A [max_size];
    double array_B [max_size];
    int array_A_size;
    int array_B_size;
    double mean_A;
    double median_A;
    double low_A;
    double high_A;
    double standard_deviation_A;
    double mean_B;
    double median_B;
    double low_B;
    double high_B;
    double standard_deviation_B;
    
    array_A_size = build_array("data7A.txt", array_A);
    print_array("Unsorted Set A", array_A_size, array_A);
    
    array_B_size = build_array("data7B.txt", array_B);
    print_array("Unsorted Set B", array_B_size, array_B);
    
    sort_array(array_A, array_A_size);
    print_array("Sorted Set A", array_A_size, array_A);
    
    sort_array(array_B, array_B_size);
    print_array("Sorted Set B", array_B_size, array_B);
    
    mean_A = mean(array_A, array_A_size);
    mean_B = mean(array_B, array_B_size);
    
    median_A = median(array_A, array_A_size);
    median_B = median(array_B, array_B_size);
    
    low_A = low(array_A, array_A_size);
    low_B = low(array_B, array_B_size);
    
    high_A = high(array_A, array_A_size);
    high_B = high(array_B, array_B_size);
    
    standard_deviation_A = standard_deviation(array_A, array_A_size);
    standard_deviation_B = standard_deviation(array_B, array_B_size);
    
    cout << endl << endl << "Set A Statistics" << endl << endl
        << setw(29) << left << "Mean:" << right << mean_A << "   " << setw(29) << left << "Median: " << right << median_A << endl
        << setw(29) << left << "Low:" << right << low_A << "   " << setw(29) << left << "High: " << right << high_A << endl
        << setw(29) << left << "Standard Deviation:" << right << standard_deviation_A << endl;
    
    cout << endl << endl << "Set B Statistics" << endl << endl
        << setw(29) << left << "Mean:" << right << mean_B << "   " << setw(29) << left << "Median: " << right << median_B << endl
        << setw(29) << left << "Low:" << right << low_B << "   " << setw(29) << left << "High: " << right << high_B << endl
        << setw(29) << left << "Standard Deviation:" << right << standard_deviation_B << endl;
    
    display_differences(mean_A, mean_B, median_A, median_B, standard_deviation_A, standard_deviation_B);
    
    return 0;
}

/*0===[============>
Function: build_array

Use: function that applies information found in a .txt file to an array of doubles

Arguments: double_temp - a temporary variable that is specifically a double
           array_size - the size of the current array in the function

Returns: array_size

Note: opens and closes the .txt file and checks if open
<============]===0*/
int build_array(string file_name, double array[])
{
    double double_temp;
    int array_size = 0;
    
    ifstream inFile;
    
    inFile.open(file_name);
    
    if ( inFile.fail() )
    {
      cout << "ERROR: Could not open " << file_name << " file.  Terminating." << endl;
      exit(-1);
    }
    
    inFile >> double_temp;
    
    while (double_temp != end_character)
    {
        array[array_size] = double_temp;
        
        array_size++;
        
        inFile >> double_temp;
    }
    
    inFile.close();
    
    return array_size;
}

/*0===[============>
Function: print_array

Use: takes the information from the array put into it and displays it pretty

Arguments: i - generic counter

Returns: nothing

Note:
<============]===0*/
void print_array(string title, int size, double array[])
{
    int i;
    
    cout << fixed << setprecision(2) << title << endl << endl;
    
    for (i = 0; i < size; i++)
    {
        if ((i + 1) % (line_length) == 0)
        {
            cout << array[i] << endl;
        }
        else
        {
            cout << array[i] << " ";
        }
    }
    
    cout << endl << endl;
}

/*0===[============>
Function: sort_array

Use: function that selection sorts the array inserted

Arguments: i - generic counter
           j - generic counter
           min_index - keeps track of what's already been sorted
           transfer_variable - variable used to store what's being transfered

Returns: nothing

Note: standard selection sort
<============]===0*/
void sort_array(double array[], int size)
{
    int i = 0;
    int j = 0;
    int min_index;
    int transfer_variable;
    
    while (i < size - 1)
    {
        min_index = i;
        j = i + 1;
        while (j < size)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            };
            j += 1;
        };
        transfer_variable = array[i];
        array[i] = array[min_index];
        array[min_index] = transfer_variable;
        i += 1;
    };
}

/*0===[============>
Function: mean

Use: function that calculates the mean of the array inserted

Arguments: i - generic counter
           mean - holds the calculated mean

Returns: mean

Note:
<============]===0*/
double mean(double array[], int size)
{
    double mean;
    int i;
    
    mean = array[0];
    
    for (i = 1; i < size; i++)
    {
        mean = mean + array[i];
    }
    
    mean = mean / size;
    
    return mean;
}

/*0===[============>
Function: median

Use: function that calculates the median of the array inserted

Arguments: i - generic counter
           median - holds the calculated median

Returns: median

Note:
<============]===0*/
double median(double array[], int size)
{
    double median;
    
    if (size % 2 == 0)
    {
        median = array[(size / 2)] + array[(size / 2) + 1];
        median = median / 2;
    }
    else
    {
        int i;
        
        i = (size / 2) + .5;
        
        median = array[i];
    }
    
    return median;
}

/*0===[============>
Function: low

Use: function that calculates the lowest number in the array inserted

Arguments: low - holds the gathered low number

Returns: low

Note:
<============]===0*/
double low(double array[], int size)
{
    double low;
    
    low = array[0];
    
    return low;
}

/*0===[============>
Function: high

Use: function that calculates the highest number in the array inserted

Arguments: high - holds the gathered high number

Returns: high

Note:
<============]===0*/
double high(double array[], int size)
{
    double high;
    
    high = array[size - 1];
    
    return high;
}

/*0===[============>
Function: standard_deviation

Use: function that calculates the standard deviation of the array inserted

Arguments: standard_deviation - holds the calculated standard deviation
           i - generic counter
           x_square_of_sum - ( (Ex)^2 )is first summed then squared(labeled x so I can easier diferentiate it)
           y_square_of_sum - ( E(x^2) )is first squared then summed(labeled y so I can easier diferentiate it)

Returns: standard deviation

Note: using sqrt for square root through cmath
<============]===0*/
double standard_deviation(double array[], int size)
{
    double standard_deviation;
    int i;
    double x_square_of_sum;
    double y_sum_of_square;
    
    x_square_of_sum = array[0];
    y_sum_of_square = array[0] * array[0];
    
    for (i = 1; i < size; i++)
    {
        x_square_of_sum = x_square_of_sum + array[i];
    }
    
    x_square_of_sum = x_square_of_sum * x_square_of_sum;
    
    for (i = 1; i < size; i++)
    {
        y_sum_of_square = y_sum_of_square + (array[i] * array[i]);
    }
    
    standard_deviation = y_sum_of_square - (x_square_of_sum / size);
    
    standard_deviation = standard_deviation / (size - 1);
    
    standard_deviation = sqrt(standard_deviation);
    
    return standard_deviation;
}

/*0===[============>
Function: display_differences

Use: function that displays the differences in mean median and standard deviation

Arguments: mean_difference - holds the mean difference
           median_difference - holds the median difference
           standard_deviation_difference - holds the standard deviation difference

Returns: nothing

Note: chacking to make sure which one is larger
<============]===0*/
void display_differences(double mean_A, double mean_B, double median_A, double median_B, double standard_deviation_A, double standard_deviation_B)
{
    double mean_difference;
    double median_difference;
    double standard_deviation_difference;
    
    if (mean_A > mean_B)
    {
        mean_difference = mean_A - mean_B;
    }
    else
    {
        mean_difference = mean_B - mean_A;
    }
    
    if (median_A > median_B)
    {
        median_difference = median_A - median_B;
    }
    else
    {
        median_difference = median_B - median_A;
    }
    
    if (standard_deviation_A > standard_deviation_B)
    {
        standard_deviation_difference = standard_deviation_A - standard_deviation_B;
    }
    else
    {
        standard_deviation_difference = standard_deviation_B - standard_deviation_A;
    }
    
    cout << endl << endl << "Differences" << endl << endl
        << setw(29) << left << "Mean:" << right << mean_difference << endl
        << setw(29) << left << "Median:" << right << median_difference << endl
        << setw(29) << left << "Standard Deviation:" << right << standard_deviation_difference << endl;
}
