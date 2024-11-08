//240 Lowest Value daily

#include <iostream>
#include <iomanip>

using namespace std;

#define ARRAY_SIZE 20

void lowestValue(int [], int [], int [], int);
void printArray(int [], int [], int [], int);

int main()
  {
  int one[ARRAY_SIZE] = {36, 54, 41, 86, 40, 7, 77, 21, 20, 99, 73, 75, 16, 78, 40, 23, 76, 50, 10, 22};
  int two[ARRAY_SIZE] = {95, 17, 16, 41, 63, 53, 33, 66, 16, 38, 11, 68, 0, 31, 15, 29, 80, 56, 95, 82};
  int three[ARRAY_SIZE] = {60, 10, 52, 88, 78, 83, 46, 89, 68, 49, 52, 49, 25, 78, 74, 42, 52, 12, 41, 23};
  int four[ARRAY_SIZE] = {3, 67, 10, 99, 96, 63, 40, 2, 11, 28, 30, 22, 87, 72, 60, 30, 38, 64, 72, 32};
  int five[ARRAY_SIZE] = {45, 24, 68, 42, 13, 74, 65, 83, 86, 39, 7, 94, 80, 98, 46, 49, 24, 16, 72, 73};
  int six[ARRAY_SIZE] = {-45, -24, -68, -42, -13, -74, -65, -83, -86, -39, -7, -94, -80, -98, -46, -49, -24, -16, -72, -73};

  int test_num;
  
  cout << "Test number? ";
  cin >> test_num;
  
  if(test_num == 1)
    {
    //Display the smallest values in the one, two, and three arrays

    cout << endl << "Test 1: display the smallest values from arrays one, two, and three" << endl;

    printArray(one, two, three, ARRAY_SIZE);
    lowestValue(one, two, three, ARRAY_SIZE);
    }
  else if(test_num == 2)
    {
    //Display the smallest values in the four, five, and six arrays
    cout << endl << "Test 2: display the smallest values from arrays four, five, and six" << endl;

    printArray(four, five, six, ARRAY_SIZE);
    lowestValue(four, five, six, ARRAY_SIZE);
    }
  else if(test_num == 3)
    {
    //Display the smallest values in the four, five, and six arrays
    cout << endl << "Test 3: display the smallest values from arrays two, four, and six" << endl;

    printArray(two, four, six, ARRAY_SIZE);
    lowestValue(two, four, six, ARRAY_SIZE);
    }
  else if(test_num == 4)
    {
    //Display the smallest values in the four, five, and six arrays
    cout << endl << "Test 4: display the smallest values from arrays one, three, and five" << endl;

    printArray(one, three, five, ARRAY_SIZE);
    lowestValue(one, three, five, ARRAY_SIZE);
    }
  else
    {
    //Display the smallest values in the four, five, and six arrays
    cout << endl << "Test 5: display the smallest values from arrays one, four, and six"
         << endl << "        -- using first " << ARRAY_SIZE/2 + 1 << " values only" << endl;

    printArray(one, four, six, ARRAY_SIZE/2 + 1);
    lowestValue(one, four, six, ARRAY_SIZE/2 + 1);
    }

  return 0;
}


//This function prints three arrays of integers
void printArray(int one[], int two[], int three[], int numVals)
{
  cout << endl << "First array" << endl;
  for (int i = 0; i < numVals; i++)
  {
      cout << setw(4) << one[i];
  }

  cout << endl << endl << "Second array" << endl;
  for (int i = 0; i < numVals; i++)
  {
      cout << setw(4) << two[i];
  }

  cout << endl << endl << "Third array" << endl;
  for (int i = 0; i < numVals; i++)
  {
      cout << setw(4) << three[i];
  }
  cout << endl;
}

void lowestValue(int array_A[], int array_B[], int array_C[], int size)
{
    int i;
    int low_A = 0;
    int low_B = 0;
    int low_C = 0;
    int lowest;
    
    low_A = array_A[0];
    
    for (i = 1; i < size; i++)
    {
        if (low_A > array_A[i])
        {
            low_A = array_A[i];
        }
    }
    
    cout << "low in 1st array == " << low_A << endl;
    
    low_B = array_B[0];
    
    for (i = 1; i < size; i++)
    {
        if (low_B > array_B[i])
        {
            low_B = array_B[i];
        }
    }
    
    cout << "low in 2nd array == " << low_B << endl;
    
    low_C = array_C[0];
    
    for (i = 1; i < size; i++)
    {
        if (low_C > array_C[i])
        {
            low_C = array_C[i];
        }
    }
    
    cout << "low in 3rd array == " << low_C << endl << endl;
    
    if (low_A < low_B && low_A < low_C)
    {
        lowest = low_A;
    }
    else if (low_B < low_A && low_B < low_C)
    {
        lowest = low_B;
    }
    else
    {
        lowest = low_C;
    }
    
    cout << "lowest value == " << lowest << endl;
}
