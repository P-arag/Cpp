#include <iostream>

using namespace std;

int digital_root(int n);

int main()
{
    int num = 0;
    cout << "Enter the number <: ";
    cin >> num;
    cout << "The digital root of " << num << " by looping is <: " << digital_root(num) << endl;

    return 0;
}

int digital_root(int n)
{
    int sum = 0;
    int digitalRoot = n;
    while (digitalRoot > 10)
    {
        n = digitalRoot;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        digitalRoot = sum;
        sum = 0;
    }
    return digitalRoot;
}
