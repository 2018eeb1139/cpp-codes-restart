vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> s;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        int x = nums[i];
        int target = (-1) * x;
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                s.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
    }
    for (auto &v : s)
    {
        ans.push_back(v);
    }
    return ans;
}