int Solution::solve(vector<vector<int>> &A)
{
    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < A.size(); i++)
    {
        int start = A[i][0];
        int end = A[i][1];
        if (pq.empty())
        {
            pq.push(end);
        }
        else
        {
            if (pq.top() > start)
            {
                pq.push(end);
            }
            else if (pq.top() <= start)
            {
                pq.pop();
                pq.push(end);
            }
        }
    }
    return pq.size();
}
