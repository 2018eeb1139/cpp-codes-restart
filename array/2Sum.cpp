vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            return {i + 1, j + 1};
        }
        else if (numbers[i] + numbers[j] > target)
            j--;
        else if (numbers[i] + numbers[j] < target)
            i++;
    }
    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) == m.end())
        {
            m[target - nums[i]] = i;
        }
        else
        {
            res.push_back(i);
            res.push_back(m[nums[i]]);
        }
    }
    return res;
}