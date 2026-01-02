// NGR Index
// Like Stock span
vector<int> dailyTemperatures(vector<int> &arr)
{
    int n = arr.size();
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(0);
        }
        else if (s.size() > 0 && s.top().first > arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
                s.pop();
            if (s.size() == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            continue;
        else
        {
            v[i] = v[i] - i;
        }
    }
    return v;
}