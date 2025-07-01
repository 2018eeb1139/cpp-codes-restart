int Solution::solve(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (st.size() > 0 && s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.size();
}
