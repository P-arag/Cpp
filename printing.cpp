#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    string out = "The addition is:- ";
    int num1, num2;
    cout << "Enter the first number:- ";
    cin >> num1;
    cout << "Enter the second number:- ";
    cin >> num2;
    cout << out << num1 + num2;
    getche();
    return 0;
}