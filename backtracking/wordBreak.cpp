#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> ans;
void solve(string &s, vector<string> &res, unordered_set<string> &dict, int start)
{
    if (start == s.size())
    {
        string sentence;
        for (int i = 0; i < res.size(); i++)
        {
            sentence += res[i];
            if (i != res.size() - 1)
            {
                sentence += ' ';
            }
        }
        ans.push_back(sentence);
        return;
    }
    for (int i = start; i < s.size(); i++)
    {
        if (dict.find(s.substr(start, i - start + 1)) != dict.end())
        {
            res.push_back(s.substr(start, i - start + 1));
            solve(s, res, dict, i + 1);
            res.pop_back();
        }
    }
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> res;
    solve(s, res, dict, 0);
    return ans;
}