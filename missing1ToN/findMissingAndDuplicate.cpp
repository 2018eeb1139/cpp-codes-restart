vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    vector<int> v;
    vector<int> count(n + 1, 0);
    for (int i = 0; i < A.size(); i++)
    {
        count[A[i]] += 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (count[i] == 2)
        {
            v.push_back(i);
        }
        else if (count[i] == 0)
        {
            v.push_back(i);
        }
        if (v.size() == 2)
            break;
    }
    return v;
}

vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    long long sum_n = (long long)n * (n + 1) / 2;
    long long sum_sq_n = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long sum_arr = 0, sum_sq_arr = 0;
    for (int num : A)
    {
        sum_arr += (long long)num;
        sum_sq_arr += (long long)num * num;
    }

    long long diff = sum_n - sum_arr;          // X - Y
    long long sq_diff = sum_sq_n - sum_sq_arr; // X^2 - Y^2

    long long sum = sq_diff / diff; // X + Y

    long long missing = (diff + sum) / 2;
    long long repeating = missing - diff;

    return {(int)repeating, (int)missing};
}
