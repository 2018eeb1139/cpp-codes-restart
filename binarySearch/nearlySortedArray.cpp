#include <iostream>
#include <vector>
using namespace std;

int findTarget(vector<int> &arr, int target)
{
    // Your code here
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == arr[mid])
        {
            return mid;
        }
        else if (mid - 1 >= start && target == arr[mid - 1])
        {
            return mid - 1;
        }
        else if (mid + 1 <= end && target == arr[mid + 1])
        {
            return mid + 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 2;
        }
        else
            end = mid - 2;
    }
    return -1;
}