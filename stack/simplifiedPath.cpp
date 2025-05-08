string simplifyPath(string path)
{
    stack<string> s;
    string ans = "";
    int n = path.size();
    int i = 0;
    int j = i + 1;
    while (j < n)
    {
        if (path[j] == '/')
        {
            i++;
            j++;
            continue;
        }
        while (j < n && path[j] != '/')
        {
            j++;
        }
        string x = path.substr(i + 1, j - i - 1);
        if (x == "..")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
        else if (!x.empty() && x != ".")
        {
            s.push(x);
        }
        i = j;
        j = i + 1;
    }
    while (!s.empty())
    {
        ans = "/" + s.top() + ans;
        s.pop();
    }
    return ans.empty() ? "/" : ans;
}