#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> ans;
void solve(string &s, string &res, int start, map<char, string> &m)
{
    if (start == s.size())
    {
        ans.push_back(res);
        return;
    }
    for (auto c : m[s[start]])
    {
        res.push_back(c);
        solve(s, res, start + 1, m);
        res.pop_back();
    }
}
vector<string> letterCombinations(string s)
{
    if (!s.size())
        return ans;
    map<char, string> m;
    m.clear();
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    string res;
    solve(s, res, 0, m);
    return ans;
}

// Interviewbit

vector<string> ans;

void solve(string &s, int idx, string temp, unordered_map<char, string> &m)
{
    if (idx == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (char &c : m[s[idx]])
    {
        temp.push_back(c);
        solve(s, idx + 1, temp, m);
        temp.pop_back();
    }
}

vector<string> Solution::letterCombinations(string s)
{
    unordered_map<char, string> m;
    m['0'] = "0";
    m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    ans.clear();
    string temp = "";
    solve(s, 0, temp, m);

    return ans;
}
