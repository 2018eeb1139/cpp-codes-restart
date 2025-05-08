int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int max_sum = INT_MIN;
    int curr_sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum1 += nums[i];
        max_sum = max(max_sum, curr_sum1);
        if (curr_sum1 < 0)
        {
            curr_sum1 = 0;
        }
    }
    int min_sum = INT_MAX;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += nums[i];
        min_sum = min(min_sum, curr_sum);
        if (curr_sum > 0)
        {
            curr_sum = 0;
        }
    }
    int cir_sum = total_sum - min_sum;
    if (max_sum > 0)
    {
        return max(max_sum, cir_sum);
    }
    else
    {
        return max_sum;
    }
}