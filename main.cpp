#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>

using namespace std;

#define MOD 1000000007
#define ll long long int
const int M = 1e9 + 7;
const int N = 1e+7;
int hsh[1000];
vector<vector<int>> subsets;

void generate(vector<int> &subset, int i, vector<int> &nums)
{
    if (i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }
    // not including the ith element
    generate(subset, i + 1, nums);
    subset.push_back(nums[i]);

    // including the ith element
    generate(subset, i + 1, nums);
    subset.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> empty;
    generate(empty, 0, nums);

    for (auto subset : subsets)
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
