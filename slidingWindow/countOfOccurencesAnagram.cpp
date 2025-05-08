#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "forxxorfxdofr";
    string ptr = "for";
    int k = ptr.size();
    int i = 0, j = 0;
    int ans = 0;
    unordered_map<char, int> m;
    for (char c : ptr)
    {
        m[c]++;
    }
    int count = m.size();
    while (j < s.size())
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
                ans++;
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    count++;
            }
            i++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
