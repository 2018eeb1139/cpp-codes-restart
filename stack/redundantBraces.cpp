int Solution::braces(string s)
{
    stack<char> st;
    for (char &c : s)
    {
        if (c == ')')
        {
            bool hasOperator = false;
            while (!st.empty() && st.top() != '(')
            {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    hasOperator = true;
                }
            }
            st.pop();
            if (!hasOperator)
                return 1;
        }
        else
        {
            st.push(c);
        }
    }
    return 0;
}
