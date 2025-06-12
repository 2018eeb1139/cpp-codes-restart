int Solution::removeDuplicates(vector<int> &v)
{
    int i = 1;
    for (int j = 1; j < v.size(); j++)
    {
        if (v[j] != v[i - 1])
        {
            v[i] = v[j];
            i++;
        }
    }
    return i;
}