#include <bits/stdc++.h>
using namespace std;

// pick toys is same problem
int main()
{
    string s = "aabaaab";
    int k = 2;
    unordered_map<char, int> m;
    int i = 0, j = 0;
    int mx = -1;
    while (j < s.size())
    {
        m[s[j]]++;
        if (m.size() < k)
        {
            j++;
        }
        else if (m.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (m.size() > k)
        {
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == k)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
    }
    cout << mx << endl;
}
