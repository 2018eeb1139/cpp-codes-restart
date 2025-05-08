#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>

int dp[1005][1005]; // Define DP table

int func(vector<int> &wt, vector<int> &val, int idx, int W)
{
    // Base cases
    if (W == 0)
        return 0; // No remaining capacity
    if (idx < 0)
        return 0; // No items left to consider

    if (dp[idx][W] != -1) // Check if already computed
        return dp[idx][W];

    // Exclude the current item
    int ans = func(wt, val, idx - 1, W);

    // Include the current item if it fits
    if (wt[idx] <= W)
    {
        ans = max(ans, func(wt, val, idx - 1, W - wt[idx]) + val[idx]);
    }

    return dp[idx][W] = ans; // Store the result in dp table
}

// Function to return max value that can be put in knapsack of capacity
int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
    int n = val.size();
    return func(wt, val, n - 1, capacity); // Start from the last item
}

int main()
{
    int capacity = 4,
        vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    cout << knapSack(4, val, wt);
}
