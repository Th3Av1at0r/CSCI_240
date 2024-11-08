/*0===[============>
CSCI 240         Program 1     Fall 2019

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Friday, January 26

Purpose: The purpose of this program is to calculate and display
         the gravitational force between two objects.

         The user provides the mass of the two objects and the
         distance between the objects.
 <============]===0*/

#include <iostream>

using namespace std;

double get_mass(double mass)
{
    cout << "Enter the mass of object " << mass <<" (in kilograms): ";
    cin >> mass;
    
    return mass;
}

double get_distance(double distance)
{
    cout << "Enter the distance between the 2 objects (in meters): ";
    cin >> distance;
    
    return distance;
}

double calculate_force(double first_mass, double second_mass, double distance, double force)
{
    double gravitational_constant = 0.0000000000667;
    
    
    force = (gravitational_constant * first_mass * second_mass);
    force =  (force / (distance * distance));
    
    return force;
}

void print_results(double force)
{
    cout << "\n\nThe force of gravitational attraction is: " << force << " newtons." << endl;
}

int main()
{
    double distance = 0;
    double first_mass = 1;
    double second_mass = 2;
    double force = 0;

    cout << "****************************************"
    << "\n\tGravitational Force Calculator"
    << "\n****************************************\n\n";
    
    first_mass = get_mass(first_mass);
    second_mass = get_mass(second_mass);
    distance = get_distance(distance);
    force = calculate_force(first_mass, second_mass, distance, force);
    
    print_results(force);
    
    return 0;
}
