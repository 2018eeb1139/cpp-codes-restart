#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>

// bool func(int idx,int target){
//     if(target==0) return true;
//     if(idx<0) return false;
//     bool ispos = func(idx-1,target,arr);
//     if(target-arr[idx]>=0){
//         ispos = (func(idx-1,target-arr[idx],arr) || func(idx-1,target,arr));
//     }
//     return ispos;
// }

int minDifference(vector<int> &arr)
{
    // Your code goes here
    int n = arr.size();
    long long sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> v;
    for (int j = 0; j < (sum + 1); j++)
    {
        if (dp[n][j])
            v.push_back(j);
    }
    long long mn = INT_MAX;
    for (int x : v)
    {
        mn = min(mn, abs(sum - (2 * x)));
    }
    return mn;
}