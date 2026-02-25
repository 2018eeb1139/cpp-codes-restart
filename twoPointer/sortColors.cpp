void sortColors(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(3, 0);
    for (int &x : nums)
    {
        v[x]++;
    }
    int idx = 0;
    int i = 0;
    while (idx < 3)
    {
        while (v[idx]--)
        {
            nums[i] = idx;
            i++;
        }
        idx++;
    }
}