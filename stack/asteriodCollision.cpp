vector<int> asteroidCollision(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    stack<int> st;
    int i = 0;
    while (i < n)
    {
        if (!st.empty() && a[i] < 0 && st.top() > 0)
        {
            int sum = a[i] + st.top();
            if (sum < 0)
            {
                st.pop();
            }
            else if (sum > 0)
            {
                i++;
            }
            else
            {
                st.pop();
                i++;
            }
        }
        else
        {
            st.push(a[i]);
            i++;
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}