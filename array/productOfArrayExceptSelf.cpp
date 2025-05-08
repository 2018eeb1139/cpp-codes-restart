#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    vector<int> pf_prod(n);
    vector<int> sf_prod(n);
    pf_prod[0] = nums[0];
    sf_prod[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
    {
        pf_prod[i] = pf_prod[i - 1] * nums[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        sf_prod[i] = sf_prod[i + 1] * nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ans[i] = sf_prod[i + 1];
        else if (i == n - 1)
            ans[i] = pf_prod[i - 1];
        else
            ans[i] = pf_prod[i - 1] * sf_prod[i + 1];
    }
    return ans;
}