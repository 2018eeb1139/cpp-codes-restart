int findMin(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int idx = -1;
    while (start <= end)
    {
        // array is already sorted
        if (arr[start] <= arr[end])
        {
            idx = start;
            break;
        }
        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            idx = mid;
            break;
        }
        else if (arr[start] <= arr[mid])
        {
            start = mid + 1;
        }
        else if (arr[mid] <= arr[end])
        {
            end = mid - 1;
        }
    }
    return arr[idx];
}