int subarraySum(vector<int> &arr, int k)
{
    int ct = 0;
    unordered_map<int, int> m;
    vector<int> pf_sum(arr.size());
    pf_sum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        pf_sum[i] = pf_sum[i - 1] + arr[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (pf_sum[i] == k)
            ct++;

        if (m.find(pf_sum[i] - k) != m.end())
        {
            ct += m[pf_sum[i] - k];
        }
        m[pf_sum[i]]++;
    }
    return ct;
}