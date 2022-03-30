/*Create a class by the name date with member data day, month and year... Overload any two relational
operators... Overload ++ operator to increment the date by one day... Overload the + operator to
add given number of days to the specific date... Provide the function to evaluate the number of days
elapsed of the current year of the date by the help of object...*/
#include <iostream>
using namespace std;
class Date                  // Class for evaluation of dates
{
    public:     // Data members of day, month and year representing date
    int day;
    int month;
    int year;
    public:
    Date()        // Default Constructor
    {
        day = 0; month = 0; year = 0;
    }
    public:
    Date(int d, int m, int y)    // Parametrized Constructor
    {
        day = d; month = m; year = y;
    }
    friend Date operator -- (Date &obj);   // Operator Overloading
    friend void operator !  (Date &obj);
    friend Date operator ++ (Date &obj);
    friend Date operator + (Date &obj, Date &obj1);
    int DaysElapsed(Date &obj);    // Function for evaluating days elapsed
};
int main()
{
    int x, y, z;
    cout << "Enter day : ";
    cin >> x;
    cout << "Enter month : ";
    cin >> y;
    cout << "Enter year : ";
    cin >> z;
    Date object(x, y, z);        // Object creation by Parametrized Constructor
    cout << "Enter day : ";
    cin >> x;
    cout << "Enter month : ";
    cin >> y;
    cout << "Enter year : ";
    cin >> z;
    Date object1(x, y, z);   // Object creation by Parametrized Constructor
    Date object2 = object + object1;     // Operator Overloading
    cout << "The new Date is :" << object2.day << "/" << object2.month << "/" << object2.year << endl;
    object2 = ++object2;     // Operator Overloading
    cout << "The date is incremented !" << endl;
    cout << "" << object2.day << "/" << object2.month << "/" << object2.year << endl;
    object2 = --object2;     // Operator Overloading
    cout << "The date is decremented !" << endl;
    cout << "" << object2.day << "/" << object2.month << "/" << object2.year << endl;
    !object2;       // Operator Overloading
    x = object2.DaysElapsed(object2);    // Function call
    cout << "The Days elapsed are : " << x << endl;
    return 0;    // End of the program
}
Date operator + (Date &obj, Date &obj1)    // Operator Overload to add dates
{
    Date temp;     // Temporary object creation
    temp.day = obj.day + obj1.day;            // Temporary object initalisation to the sum
    temp.month = obj.month + obj1.month;
    temp.year = obj.year + obj1.year;
    if(temp.day > 30)      // Conversion to extra dates to month
    {
        temp.day -= 30;
        temp.month++;
    }
    if(temp.month > 12)   // Conversion of extra months to year
    {
        temp.month -= 12;
        temp.year++;
    }
    return temp;
}
Date operator ++ (Date &obj)   // Operator Overload to Increment date
{
    Date temp = obj;
    temp.day++;         // Incrementing date
    return temp;
}
Date operator -- (Date &obj)   // Operator Overload to decrement date
{
    Date temp = obj;
    temp.day--;           // Decrementing date
    return temp;
}
void operator ! (Date &obj)
{
    if(obj.year % 4 == 0)  // Operator Overload to check if it is a Leap Year or not
        cout << "The Year is a Leap Year !!" << endl;
    else
        cout << "The Year is not a Leap Year !!" << endl;
    return;
}
int Date::DaysElapsed(Date &obj)   // Declaring function outside by scope resolution
{
    int days;
    days = obj.month * 30 + obj.day;   // Evaluating days elapsed
    return days;
}