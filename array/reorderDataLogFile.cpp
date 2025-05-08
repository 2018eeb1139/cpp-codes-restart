bool cmp(pair<string, string> a, pair<string, string> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

vector<string> Solution::reorderLogs(vector<string> &logs)
{
    vector<string> letter_logs;
    vector<string> digit_logs;
    for (int i = 0; i < logs.size(); i++)
    {
        string s = logs[i];
        int pos = s.find('-');
        if (isdigit(s[pos + 1]))
        {
            digit_logs.push_back(s);
        }
        else
        {
            letter_logs.push_back(s);
        }
    }
    vector<pair<string, string>> v;
    for (int i = 0; i < letter_logs.size(); i++)
    {
        string s = letter_logs[i];
        int j = 0;
        while (j < s.size() && s[j] != '-')
        {
            j++;
        }
        v.push_back(make_pair(s.substr(j + 1), s.substr(0, j)));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        letter_logs[i] = v[i].second + '-' + v[i].first;
    }
    for (auto &s : digit_logs)
    {
        letter_logs.push_back(s);
    }
    return letter_logs;
}
