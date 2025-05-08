#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> subsets;

// using recursion (on strings)
void solve(string ip, string op)
{
    if (ip.size() == 0)
    {
        op.size() == 0 ? cout << "space\n" : cout << op << "\n";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
    return;
}

// subsets using recursion on array
void solve(vector<int> ip, vector<int> op)
{
    if (ip.size() == 0)
    {
        subsets.push_back(op);
        return;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
    return;
}

// printing unique subsets
set<vector<int>> s;
void solve(vector<int> ip, vector<int> op)
{
    if (ip.size() == 0)
    {
        s.insert(op);
        return;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
    return;
}
vector<vector<int>> subsetsWithDup(vector<int> &ip)
{
    sort(ip.begin(), ip.end());
    vector<int> op;
    solve(ip, op);
    vector<vector<int>> ans;
    for (auto v : s)
    {
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    vector<int> ip = {1, 2, 2};
    vector<int> op;
    solve(ip, op);
    for (auto vec : subsets)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// using bit maksing
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subset_ct; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main()
{
    string ip = "abcd";
    string op = "";
    solve(ip, op);
}
