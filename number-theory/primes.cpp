#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N, 0);
vector<int> divisor[N];
int sum[N];

int main()
{
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j = j + i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
    // cout<<isPrime[91]<<" "<<lp[91]<<" "<<hp[91];
    int num;
    cin >> num;
    vector<int> prime_factors;
    map<int, int> prime_factors_ct;

    while (num > 1)
    {
        int prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            num = num / prime_factor;
            prime_factors.push_back(prime_factor);
            prime_factors_ct[prime_factor]++;
        }
    }
    for (auto factors : prime_factors)
    {
        cout << factors << " ";
    }
    cout << endl;
    for (auto factors : prime_factors_ct)
    {
        cout << factors.first << " " << factors.second;
        cout << endl;
    }

    // divisors
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisor[j].push_back(i);
            sum[j] += i;
        }
    }
}
