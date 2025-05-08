// variation of longest substring with k unique characters
// that is all unique characters

int lengthOfLongestSubstring(string s)
{
    int mx = 0, i = 0, j = 0;
    unordered_map<char, int> m;
    while (j < s.size())
    {
        m[s[j]]++;
        if (m.size() == j - i + 1)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == j - i + 1)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
    }
    return mx;
}