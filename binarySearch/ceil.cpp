#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &arr, int target)
{
    int n = arr.size();
    if (target > arr[n - 1])
        return n;
    int res = -1;
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return res = mid;
        else if (arr[mid] > target)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return res;
}