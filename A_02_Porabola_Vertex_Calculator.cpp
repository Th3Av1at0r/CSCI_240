/*0===[============>
CSCI 240         Program 3     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, February 9

Purpose: Calculate and display the X and Y-coordinates for the coordinate of a parabola and
        determine (and display) the concavity of the parabola,
        and if the parabola has real roots and what they are if they exist.
 <============]===0*/

#include <iostream>
#include <iomanip>

using namespace std;

const int label_spaces = 20;
const int value_spaces = 11;

int get_coefficient(int coefficient, char coefficient_letter)
{
    // if statement to see which variable is being asked about for different outputs
    if (coefficient_letter == 'a')
    {
        // while statement to make sure there is no 0 entered
        while (true == true)
        {
            cout << "Enter the " << coefficient_letter << " Coefficient (non-zero value): ";
            cin >> coefficient;
            
            if (coefficient == 0)
            {
                cout << "Error: the a-Coefficient MUST be non-zero. Try again: 1" << endl;
                continue;
            }
            break;
        }
    }
    else
    {
        cout << "\nEnter the " << coefficient_letter <<" Coefficient: ";
        cin >> coefficient;
    }
    
    return coefficient;
}

double calculate_x_coordinate(double x_coordinate, int coefficient_a, int coefficient_b)
{
    // equation for x coordinate
    x_coordinate = -coefficient_b;
    x_coordinate = (x_coordinate / (2 * coefficient_a));
    
    return x_coordinate;
}

double calculate_y_coordinate(double x_coordinate, int coefficient_a, int coefficient_b, int coefficient_c)
{
    // equation for y coordinate
    return ((coefficient_a * x_coordinate * x_coordinate) + (coefficient_b * x_coordinate) + coefficient_c);
}

string calculate_parabola_opening(int coefficient_a)
{
    // checks to see which direction the porabola is opening
    // it is already UPWARD by default
    if (coefficient_a < 0)
    {
        return "DOWNWARD";
    }
    else
    {
        return "UPWARD";
    }
}

string calculate_number_of_roots(int coefficient_a, int coefficient_b, int coefficient_c)
{
    // calculates the descriminent and returns a string value for how many root(s)
    int discriminant;
    
    discriminant = ((coefficient_b * coefficient_b)- (4 * coefficient_a * coefficient_c));
    
    if (discriminant > 0)
    {
        return "TWO roots";
    }
    else if (discriminant == 0)
    {
        return "ONE root";
    }
    
    return "NO roots";
}

double calculate_root(int coefficient_a, int coefficient_b, int coefficient_c, bool pos_neg)
{
    // re calculates the discriminant and calculates roots and uses + or - depending on
    // the bool
    double discriminant;
    
    discriminant = ((coefficient_b * coefficient_b)- (4 * coefficient_a * coefficient_c));
    
    discriminant = sqrt(discriminant);
    
    if (pos_neg == true)
    {
        return ((-coefficient_b + discriminant) / (2 * coefficient_a));
    }
    else
    {
        return ((-coefficient_b - discriminant) / (2 * coefficient_a));
    }
}

void display_result(int coefficient_a, int coefficient_b, int coefficient_c, double x_coordinate, double y_coordinate, string parabola_opening, string number_of_roots, double root_1, double root_2)
{
    // displays the table in a hopefully easy to read mannor
    cout << "\n\n" << fixed << setprecision(3)
    << "-------------------------------\n"
    << "Quadratic Equation Analyzer"
    << "\n-------------------------------\n"
    << left << setw(label_spaces) << "a Coefficient" << right << setw(value_spaces) << coefficient_a << endl
    << left << setw(label_spaces) << "b Coefficient" << right << setw(value_spaces) << coefficient_b << endl
    << left << setw(label_spaces) << "c Coefficient" << right << setw(value_spaces) << coefficient_c << endl
    << "-------------------------------" << endl
    << "Vertex" << endl
    << left << setw(label_spaces) << "X Coordinate" << right << setw(value_spaces) << x_coordinate << endl
    << left << setw(label_spaces) << "Y Coordinate" << right << setw(value_spaces) << y_coordinate << endl
    << "-------------------------------" << endl
    << "The parabola opens " << parabola_opening << endl
    << "-------------------------------" << endl
    << "The Parabola has " << number_of_roots << endl;
    
    if (number_of_roots == "TWO roots")
    {
        cout << left << setw(label_spaces) << "Root 1 - X Coordinate" << right << setw(value_spaces) << root_1 << endl
        << left << setw(label_spaces) << "Root 2 - X Coordinate" << right << setw(value_spaces) << root_2 << endl;
    }
    else if (number_of_roots == "ONE root")
    {
        cout << left << setw(label_spaces) << "Root 1 - X Coordinate" << right << setw(value_spaces) << root_1 << endl;
    }
}

int main() {
    // initalizing variables to tell appart
    int coefficient_a = 0;
    int coefficient_b = 0;
    int coefficient_c = 0;
    double x_coordinate = 0;
    double y_coordinate = 0;
    string parabola_opening = "UPWARD";
    string number_of_roots = "NO roots";
    double root_1 = 0;
    double root_2 = 0;
    
    // retrieves the 3 coefficients
    coefficient_a = get_coefficient(coefficient_a, 'a');
    coefficient_b = get_coefficient(coefficient_b, 'b');
    coefficient_c = get_coefficient(coefficient_c, 'c');
    // calculates the x and y coordinates
    x_coordinate = calculate_x_coordinate(x_coordinate, coefficient_a, coefficient_b);
    y_coordinate = calculate_y_coordinate(x_coordinate, coefficient_a, coefficient_b, coefficient_c);
    // calculates the direction of the parabola
    parabola_opening = calculate_parabola_opening(coefficient_a);
    number_of_roots = calculate_number_of_roots(coefficient_a, coefficient_b, coefficient_c);
    
    // if statement so that it only calculates what is needed
    if(number_of_roots == "TWO roots")
    {
        root_1 = calculate_root(coefficient_a, coefficient_b, coefficient_c, true);
        root_2 = calculate_root(coefficient_a, coefficient_b, coefficient_c, false);
        
    }
    else if (number_of_roots == "ONE root")
    {
        root_1 = calculate_root(coefficient_a, coefficient_b, coefficient_c, true);
    }
    
    // displays the formated results
    display_result(coefficient_a, coefficient_b, coefficient_c, x_coordinate, y_coordinate, parabola_opening, number_of_roots, root_1, root_2);
    
    return 0;
}
