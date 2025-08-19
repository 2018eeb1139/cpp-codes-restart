bool isPal(const string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int Solution::solve(string A)
{
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        if (A[i] == A[j])
        {
            i++;
            j--;
        }
        else
        {
            return isPal(A, i + 1, j) || isPal(A, i, j - 1);
        }
    }
    return 1;
}
