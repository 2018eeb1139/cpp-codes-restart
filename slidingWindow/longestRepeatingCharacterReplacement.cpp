int getMax(int freq[])
{
    int ans = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        ans = max(ans, freq[i]);
    }
    return ans;
}
int characterReplacement(string s, int k)
{
    int freq[26] = {0};
    int i = 0, j = 0;
    int res = 0;
    while (j < s.size())
    {
        freq[s[j] - 'A']++;
        int remainingMaxFreqChar = getMax(freq);
        if ((j - i + 1) - remainingMaxFreqChar <= k)
        {
            res = max(res, j - i + 1);
        }
        else if ((j - i + 1) - remainingMaxFreqChar > k)
        {
            while ((j - i + 1) - remainingMaxFreqChar > k)
            {
                freq[s[i] - 'A']--;
                i++;
            }
        }
        j++;
    }
    return res;
}