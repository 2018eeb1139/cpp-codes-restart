#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];
        int fwd[n + 1];
        int bwd[n + 1];
        fwd[0] = 0;
        bwd[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            fwd[i] = __gcd(fwd[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            bwd[i] = __gcd(bwd[i + 1], a[i]);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(fwd[l - 1], bwd[r + 1]) << endl;
        }
    }
}
