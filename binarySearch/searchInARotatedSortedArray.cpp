#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int start, int end, int target)
{
    int idx = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return idx;
}
int search(vector<int> &arr, int target)
{
    if (arr.size() == 0)
        return -1;
    if (arr.size() == 1)
    {
        return arr[0] == target ? 0 : -1;
    }
    int start = 0;
    int n = arr.size();
    int end = n - 1;
    int idx = -1;
    while (start <= end)
    {
        if (arr[start] <= arr[end])
        {
            idx = start;
            break;
        }
        int mid = start + (end - start) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            idx = mid;
            break;
        }
        else if (arr[mid] >= arr[end])
        {
            start = mid + 1;
        }
        else if (arr[start] >= arr[mid])
        {
            end = mid - 1;
        }
    }
    int ans = -1;
    int ans1 = binarySearch(arr, 0, idx - 1, target);
    int ans2 = binarySearch(arr, idx, n - 1, target);

    if (ans1 == -1 && ans2 == -1)
    {
        return -1;
    }
    else if (ans1 == -1)
    {
        ans = ans2;
    }
    else if (ans2 == -1)
    {
        ans = ans1;
    }
    return ans;
}