#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int ones, int zeros, int n, string op, vector<string> &ans)
{
    if (n == 0)
    {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    op1.push_back('1');
    solve(ones + 1, zeros, n - 1, op1, ans);
    if (ones > zeros)
    {
        string op2 = op;
        op2.push_back('0');
        solve(ones, zeros + 1, n - 1, op2, ans);
    }
    return;
}
vector<string> NBitBinary(int n)
{
    // Your code goes here
    string op = "";
    vector<string> ans;
    int ones = 0;
    int zeros = 0;
    solve(ones, zeros, n, op, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    NBitBinary(n);
}