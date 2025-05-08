int calculate(string s)
{
    stack<int> st;
    int n = s.size();
    int res = 0;
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        int curr_res = res;
        int curr_sign = sign;
        if (s[i] == ' ')
            continue;
        else if (s[i] == '+')
            sign = 1;
        else if (s[i] == '-')
            sign = -1;
        else if (s[i] == '(')
        {
            st.push(curr_res);
            st.push(curr_sign);
            res = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            int prev_sign = st.top();
            st.pop();
            int prev_res = st.top();
            st.pop();
            res = prev_res + (prev_sign * curr_res);
        }
        else
        {
            int ans = 0;
            while (i < n && isdigit(s[i]))
            {
                ans = ans * 10 + (s[i] - '0');
                i++;
            }
            i--;
            res = res + (sign * ans);
        }
    }
    return res;
}