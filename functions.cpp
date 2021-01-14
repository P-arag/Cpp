#include <iostream>
using namespace std;

double circarea(double rad)
{
    double PI = 3.141592653589793238;
    double area = PI * rad * rad;
    return area;
}
int main()
{
    double radius;
    cout << "Enter the radius of the circle:- ";
    cin >> radius;
    double area = circarea(radius);
    cout << endl
         << "The area of the circle is:- " << area;
    return 0;
}