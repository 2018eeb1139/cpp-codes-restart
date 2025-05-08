int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];
        sum = max(sum, curr_sum);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return sum;
}