int Solution::highestScore(vector<vector<string>> &A)
{
    int n = A.size();
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[A[i][0]].push_back(stoi(A[i][1]));
    }
    int mx = INT_MIN;

    for (auto x : m)
    {
        int n1 = x.second.size();
        int sum = 0;
        int curr = 0;
        for (auto i : x.second)
        {
            sum += i;
        }
        curr = sum / n1;
        mx = max(mx, curr);
        // cout<<mx<<endl;
    }
    return mx;
}
