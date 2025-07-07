int Solution::diffPossible(vector<int> &A, int B)
{
    int i = 0, j = 1;
    while (j < A.size())
    {
        if (i != j && A[j] - A[i] == B)
        {
            return 1;
        }
        // difference kam h to j badhayege kyuki array sorter h
        else if (A[j] - A[i] < B)
        {
            j++;
        }
        // diff km h to i badhdege
        else
        {
            i++;
        }
    }
    return 0;
}
