#include <iostream>
#include <vector>

using namespace std;

int largestSubarrayWithZeroSum(vector<int> &arr)
{
    int mx = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            mx = i + 1;
        }
        if (m.find(sum) != m.end())
        {
            mx = max(mx, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    return mx;
}