#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    if (b % a == 0)
    {
        return a;
    }
    return gcd(b % a, a);
    // return __gcd(a,b)
}