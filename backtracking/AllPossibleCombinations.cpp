vector<string> ans;

void solve(int idx, string &temp, vector<string> &A, int n)
{
    if (idx == n)
    {
        ans.push_back(temp);
        return;
    }
    for (char &c : A[idx])
    {
        temp.push_back(c);
        solve(idx + 1, temp, A, n);
        temp.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A)
{
    int n = A.size();
    string temp = "";
    ans.clear();
    solve(0, temp, A, n);
    sort(ans.begin(), ans.end());
    return ans;
}
