#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return -1;
}

// reverse sorted array

int reverseBinarySearch(vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
        {
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            end = mid - 1;
        }
    }
    return -1;
}

// same as max element in bitonic array
//  same as peak-index-in-a-mountain-array
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    int start = 0;
    int end = n - 1;
    int res;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                start = mid + 1;
            }
            else if (arr[mid - 1] > arr[mid])
            {
                end = mid - 1;
            }
        }
        else if (mid == 0)
        {
            if (arr[0] > arr[1])
                return 0;
            else
                return 1;
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
                return n - 1;
            else
                return n - 2;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 3, 1};
    int target = 3;
    int n = arr.size();
    int idx = findPeakElement(arr);
    int ans1 = BinarySearch(arr, 0, idx - 1, target);
    int ans2 = reverseBinarySearch(arr, idx, n - 1, target);

    if (ans1 == -1 && ans2 == -1)
    {
        return -1;
    }
    if (ans1 == -1)
    {
        return ans2;
    }
    else
    {
        return ans1;
    }
}