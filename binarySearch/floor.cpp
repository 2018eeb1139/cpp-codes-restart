#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<int> &arr, int target)
{

    // Your code here
    int res = -1;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            res = mid;
            start = mid + 1;
        }
    }
    return res;
}