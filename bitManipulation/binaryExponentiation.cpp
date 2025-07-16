#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

long long binaryExpo(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    cout << binaryExpo(3, 13);
}
