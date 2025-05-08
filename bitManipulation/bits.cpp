#include <iostream>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    int a = 9;
    printBinary(9);
    int i = 0;
    // check it ith bit is set or not;
    if ((a & (1 << i)) != 0)
    {
        cout << "set bit";
    }
    else
    {
        cout << "not set bit";
    }
    // set ith bit
    (a | (1 << i));

    // unset ith bit
    (a & (~(1 << i)));

    // toggle ith bit
    (a ^ (1 << i));

    // count set bits
    int ct = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((a & (1 << i)) != 0)
        {
            ct++;
        }
    }
    cout << ct;
    // with function
    cout << __builtin_popcount(a);
    cout << __builtin_popcountll(1LL << 35);
}