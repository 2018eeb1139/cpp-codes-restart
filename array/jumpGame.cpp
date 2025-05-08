#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    if (nums[0] == 0)
        return false;
    int maxIdx = 0; // starting at idx 0
    for (int i = 0; i < n; i++)
    {
        if (i > maxIdx)
            return false;
        maxIdx = max(maxIdx, i + nums[i]);
    }
    return true;
}