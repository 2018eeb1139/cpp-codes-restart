#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// using backtracking
void solve(vector<int> &nums, int start, vector<vector<int>> &ans)
{
    if (start == nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[start], nums[i]);
        solve(nums, start + 1, ans);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

// using recursion
void solve(string ip, string op, vector<string> &v)
{
    if (ip.size() == 0)
    {
        v.push_back(op);
        return;
    }
    for (int i = 0; i < ip.size(); i++)
    {
        string newip = ip.substr(0, i) + ip.substr(i + 1);
        string newop = op + ip[i];
        solve(newip, newop, v);
    }
    return;
}

// uniuqe permutations
void solve(string ip, string op, vector<string> &v)
{
    if (ip.size() == 0)
    {
        v.push_back(op);
        return;
    }
    unordered_set<char> s;

    for (int i = 0; i < ip.size(); i++)
    {
        if (s.find(ip[i]) == s.end())
        {
            s.insert(ip[i]);
            string newip = ip.substr(0, i) + ip.substr(i + 1);
            string newop = op + ip[i];
            solve(newip, newop, v);
        }
    }
    return;
}

int main()
{
    string s = "abc";
    vector<string> v;
    string op = "";
    solve(s, op, v);
    for (string x : v)
    {
        cout << x << endl;
    }
}

// using vector of integers
vector<vector<int>> permutations;

void solve(vector<int> ip, vector<int> op)
{
    if (ip.size() == 0)
    {
        permutations.push_back(op);
        return;
    }
    for (int i = 0; i < ip.size(); i++)
    {
        vector<int> newip = ip;
        vector<int> newop = op;
        newop.push_back(ip[i]);
        newip.erase(newip.begin() + i);
        solve(newip, newop);
    }
    return;
}

// uniuqe permutations

void solve(vector<int> ip, vector<int> op)
{
    if (ip.size() == 0)
    {
        permutations.push_back(op);
        return;
    }
    unordered_set<int> s;
    for (int i = 0; i < ip.size(); i++)
    {
        if (s.find(ip[i]) == s.end())
        {
            s.insert(ip[i]);
            vector<int> newip = ip;
            vector<int> newop = op;
            newop.push_back(ip[i]);
            newip.erase(newip.begin() + i);
            solve(newip, newop);
        }
    }
    return;
}

int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> v = {1, 1, 2};
    vector<int> op;
    solve(v, op);
    for (auto vec : permutations)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}