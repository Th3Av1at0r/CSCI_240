/*0===[============>
CSCI 240         Program 10     spring 2024

Programmer: Avi Schmookler Z2005237

Section: 02

Date Due: Thursday, May 2nd

Purpose: Implement a class called Employee that will be used to hold the information for an employee.
 
Note: Pssssssssst TA! Yeah! You! Thanks for grading all this stuff it's been a fun semester, hope you enjoyed my code! and good luck on finals!! You got this!!!!!
<============]===0*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <string.h>
#include <iomanip>

using namespace std;

/*0===[============>
Class: PiggyBank

Use: holds employee's name, identification number and salary and plays around with them

Note: fun making and using classes
<============]===0*/
class Employee
{
    
private:
    char employee_name[30];
    char employee_IN[8];
    double employee_salary;
    
public:
    Employee();
    Employee(const char[], const char[], double);
    
    void set_IN_num(const char[]);
    void set_employee_salary(double);
    void display();
    void increase_salary(double);
    const char * get_name();
    const char * get_IN_num();
    double get_salary();
};

void print_section_title(string);

int main() {
//    first bullet point
    Employee avi("Avi", "NIU5237", 53948.61);
    
//    second bullet point
    print_section_title("First Employee object:");
    avi.display();
    avi.increase_salary(125.15);
    cout << "First Employee object after raise($125.15):" << endl;
    avi.display();
    
//    third bullet point
    Employee guy;
    
//    fourth bullet point
    print_section_title("The Second Employee object:");
    guy.display();
    guy.increase_salary(-2200.00);
    cout << "The Second Employee object after raise($-2200.00):" << endl;
    guy.display();
    
//    fifth bullet point
    Employee blanche("Blanche Devereaux", "TGG1985", 820.12);
    
//    sixth bullet point
    print_section_title("The third Employee object:");
    blanche.display();
    blanche.set_employee_salary(82.88);
    blanche.set_IN_num("TGP1992");
    cout << "The third Employee object after salary change($82.88) and IN change:" << endl;
    blanche.display();
    
//    seventh bullet point
    Employee grace("Grace Hopper", "UNI1950", 2468.00);
    
//    eighth bullet point
    print_section_title("The fourth Employee object:");
    grace.display();
    grace.set_IN_num("COBOL1959");
    grace.increase_salary(9517.53);
    cout << "Displaying name and salary only of the fourth Employee object:" << endl
        << "Name: " << grace.get_name() << "\t Salary: " << grace.get_salary() << endl << endl;
    cout << "The fourth Employee object after raise($9517.53) and atempted IN change:" << endl;
    grace.display();
    
//    ninth bullet point
    Employee charlie("Charlie Hudson", "REX2332", 71940.76);
    
//    tenth bullet point
    print_section_title("The fifth Employee object:");
    charlie.display();
    charlie.set_employee_salary(-10000.01);
    cout << "Displaying IN only of the fifth Employee object:" << endl
        << "IN: " << charlie.get_IN_num() << endl << endl;
    cout << "The fifth Employee object after atempted salary change($-10000.01):" << endl;
    charlie.display();
    
//    yaaaaaaaaaaaay it's done!!!
    return 0;
}

/*0===[============>
Function: Employee

Use: Constructor to initiate the employee variables

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
Employee::Employee()
{
    strcpy(employee_name, "None");
    strcpy(employee_IN, "ACB1234");
    employee_salary = 0.00;
}

/*0===[============>
Function: Employee

Use: Alternate constructor to initiate the employee variables as inputed data

Arguments: name[] - holds the name to transfer to the employee_name vairiable
           updated_IN[] - holds the IN to transfer to the employee_IN vairiable
           salary - holds the salary to transfer to the employee_salary vairiable

Returns: nothing

Note:
<============]===0*/
Employee::Employee(const char name[], const char updated_IN[], double salary)
{
    strcpy(employee_name, name);
    set_IN_num(updated_IN);
    set_employee_salary(salary);
}

/*0===[============>
Function: set_IN_num

Use: checks validity of the updated_IN and applies it to employee_IN

Arguments: updated_IN[] - holds the IN to transfer to the employee_IN vairiable

Returns: nothing

Note:
<============]===0*/
void Employee::set_IN_num(const char updated_IN[])
{
    if (strlen(updated_IN) == 7)
    {
        if (updated_IN[0] > 64 && updated_IN[0] < 123 && updated_IN[1] > 64 &&
           updated_IN[1] < 123 && updated_IN[2] > 64 && updated_IN[2] < 123)
        {
            if (updated_IN[3] > 47 && updated_IN[3] < 58 && updated_IN[4] > 47 &&
               updated_IN[4] < 58 && updated_IN[5] > 47 && updated_IN[5] < 58 &&
               updated_IN[6] > 47 && updated_IN[6] < 58)
            {
                for (int i = 0; i < 7; i++)
                {
                    employee_IN[i] = updated_IN[i];
                }
            }
            else
            {
                cout << "ERROR(3): LAST 4 EMPLOYEE IN CHARACTERS ARE NOT ALL NUMBERS" << endl;
            }
        }
        else
        {
            cout << "ERROR(2): FIRST 3 EMPLOYEE IN CHARACTERS ARE NOT ALL ALPHABETICAL" << endl;
        }
    }
    else
    {
        cout << "ERROR(1): EMPLOYEE IN NOT 7 CHARACTERS LONG" << endl;
    }
}

/*0===[============>
Function: set_employee_salary

Use: checks validity of the salary and applies it to employee_salary

Arguments: salary - holds the salary to transfer to the employee_salary vairiable

Returns: nothing

Note:
<============]===0*/
void Employee::set_employee_salary(double salary)
{
    if(salary > 0)
    {
        employee_salary = salary;
    }
    else
    {
        cout << "ERROR(4): SALARY NOT GREATER THAN 0" << endl;
    }
}

/*0===[============>
Function: display

Use: displays the info on an employee

Arguments: N/A

Returns: nothing

Note:
<============]===0*/
void Employee::display()
{
    cout << fixed << setprecision(2) << setw(30) << left << employee_name << setw(10) << right
        << employee_IN << endl << employee_salary << endl << endl;
}

/*0===[============>
Function: increase_salary

Use: checks the validity of the salary increase and adds the increase to the current salary
     and sends it to set_employee_salary

Arguments: raise - holds the salary increase to transfer to the employee_salary vairiable

Returns: nothing

Note:
<============]===0*/
void Employee::increase_salary(double raise)
{
    if(raise > 0)
    {
        set_employee_salary(raise + employee_salary);
    }
    else
    {
        cout << "ERROR(5): RAISE NOT GREATER THAN 0" << endl;
    }
}

/*0===[============>
Function: get_name

Use: aquires employee_name

Arguments: N/A

Returns: employee_name

Note:
<============]===0*/
const char * Employee::get_name()
{
    return employee_name;
}

/*0===[============>
Function: get_IN_number

Use: aquires employee_IN

Arguments: N/A

Returns: employee_IN

Note:
<============]===0*/
const char * Employee::get_IN_num()
{
    return employee_IN;
}

/*0===[============>
Function: get_salary

Use: aquires employee_salary

Arguments: N/A

Returns: employee_salary

Note:
<============]===0*/
double Employee::get_salary()
{
    return employee_salary;
}

/*0===[============>
Function: print_section_title

Use: just here to make things look pretty

Arguments: N/A

Returns: Nothing

Note:
<============]===0*/
void print_section_title(string title)
{
    cout << "\n\n0===[=========================> <=========================]===0" << endl
        << title << endl;
}
