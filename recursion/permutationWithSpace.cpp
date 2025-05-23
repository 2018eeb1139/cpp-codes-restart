#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;
void solve(string ip, string op)
{
    if (ip.size() == 0)
    {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
    return;
}

vector<string> permutation(string ip)
{
    // Code Here
    string op = "";
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op);
    sort(ans.begin(), ans.end());
    return ans;
}