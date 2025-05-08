#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < t.length(); i++)
    {
        mp[t[i]]++;
    }
    int ans = INT_MAX;
    int i = 0, j = 0;
    int start;
    int count = mp.size();
    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        }
        if (count > 0)
            j++;
        else if (count == 0)
        {
            // A candidate for our Answer
            if (j - i + 1 < ans)
            {
                ans = j - i + 1;
                start = i;
            }
            while (count == 0)
            {
                if (mp.find(s[i]) == mp.end())
                {
                    i++;
                    if (j - i + 1 < ans)
                    {
                        ans = j - i + 1;
                        start = i;
                    }
                }
                else
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                    {
                        i++;
                        count++;
                    }
                    else
                    {
                        i++;
                        if (j - i + 1 < ans)
                        {
                            ans = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
            j++;
        }
    }
    if (ans == INT_MAX)
        return "";
    return s.substr(start, ans);
}

int main()
{
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    cout << minWindow(s, t) << endl;
}