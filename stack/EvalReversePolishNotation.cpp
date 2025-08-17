int evalRPN(vector<string> &tokens)
{
    int n = tokens.size();
    stack<int> st;
    for (auto &s : tokens)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (s == "+")
                st.push(a + b);
            else if (s == "-")
                st.push(a - b);
            else if (s == "*")
                st.push(a * b);
            else if (s == "/")
                st.push(a / b);
        }
        else
        {
            st.push(stoi(s));
        }
    }
    return st.top();
}

int Solution::evalRPN(vector<string> &A)
{
    int n = A.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            if (A[i] == "+")
            {
                st.push(val1 + val2);
            }
            if (A[i] == "-")
            {
                st.push(val2 - val1);
            }
            if (A[i] == "*")
            {
                st.push(val1 * val2);
            }
            if (A[i] == "/")
            {
                st.push(val2 / val1);
            }
        }
        else
        {
            int x = stoi(A[i]);
            st.push(x);
        }
    }
    return st.top();
}
