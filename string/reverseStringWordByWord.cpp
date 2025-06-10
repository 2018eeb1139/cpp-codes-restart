string Solution::solve(string s)
{
    stringstream ss(s);
    vector<string> res;
    string word;
    while (ss >> word)
    {
        res.push_back(word);
    }
    string ans = "";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        ans += res[i];
        if (i > 0)
            ans += ' ';
    }
    return ans;
}
