#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    // print n to 1
    cout << n << " ";
    print(n - 1);
    // print 1 to n
    cout << n << " ";
}
int fact(int n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

int main()
{
    cout << fact(7);
}
