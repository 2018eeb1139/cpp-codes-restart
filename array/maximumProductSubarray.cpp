int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int pf = 1;
    int sf = 1;
    int max_prod = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pf == 0)
        {
            pf = 1;
        }
        if (sf == 0)
        {
            sf = 1;
        }
        pf = pf * nums[i];
        sf = sf * nums[n - i - 1];
        max_prod = max(max_prod, max(pf, sf));
    }
    return max_prod;
}