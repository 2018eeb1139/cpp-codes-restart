int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> maxL(n);
    vector<int> maxR(n);
    vector<int> water(n);
    maxL[0] = height[0];
    maxR[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(maxL[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxL[i], maxR[i]) - height[i];
    }
    return accumulate(water.begin(), water.end(), 0);
}