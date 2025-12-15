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
        string s;
        cin >> s;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int hsh[26] = {0};
            for (int i = l; i <= r; i++)
            {
                hsh[s[i] - 'a']++;
            }
            int oddCt = 0;
            for (int i = 0; i < 26; i++)
            {
                if (hsh[i] & 1)
                {
                    oddCt++;
                }
            }
            if (oddCt > 1)
                cout << "No\n";
            else
                cout << "YES\n"
        }
    }
}
