#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;
bool isPalindrome(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(string &s, vector<string> &res, int start)
{
    if (start == s.size())
    {
        ans.push_back(res);
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        if (isPalindrome(s.substr(start, i - start + 1)))
        {
            res.push_back(s.substr(start, i - start + 1));
            solve(s, res, i + 1);
            res.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    ans.clear();
    vector<string> res;
    solve(s, res, 0);
    return ans;
}