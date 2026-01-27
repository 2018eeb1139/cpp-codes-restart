int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    int n = position.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({position[i], speed[i]});
    }

    sort(v.begin(), v.end());

    stack<double> st;

    for (int i = n - 1; i >= 0; i--)
    {
        double time = (double)(target - v[i].first) / v[i].second;

        if (st.empty() || time > st.top())
        {
            st.push(time);
        }
    }

    return st.size();
}