int firstNonRepeating(vector<int> &arr)
{
    // Complete the function
    unordered_map<int, int> m;
    for (int x : arr)
        m[x] += 1;
    for (int x : arr)
    {
        if (m[x] == 1)
        {
            return x;
        }
    }
    return 0;
}