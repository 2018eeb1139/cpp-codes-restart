int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    set<int> s(nums.begin(), nums.end());
    int mx = 0;
    for (int num : s)
    {
        if (s.find(num - 1) == s.end())
        {
            int curr_num = num;
            int ct = 1;
            while (s.find(curr_num + 1) != s.end())
            {
                ct++;
                curr_num += 1;
            }
            mx = max(ct, mx);
        }
    }
    return mx;
}