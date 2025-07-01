int Solution::isValid(string s)
{
    stack<char> st;

    unordered_map<char, int> m;
    m.insert({'(', -1});
    m.insert({')', 1});
    m.insert({'{', -2});
    m.insert({'}', 2});
    m.insert({'[', -3});
    m.insert({']', 3});

    if (m[s[0]] > 0)
        return 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (m[c] < 0)
        {
            st.push(c);
        }
        else if (st.size() > 0 && m[c] + m[st.top()] != 0)
        {
            return 0;
        }
        else
        {
            if (st.size() > 0)
            {
                st.pop();
            }
        }
    }
    if (st.size() == 0)
        return 1;
    else
        return 0;
}
