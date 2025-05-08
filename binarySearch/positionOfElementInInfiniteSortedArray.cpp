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

int main()
{
    int start = 0;
    int end = 1;
    int target;
    vector<int> arr;
    while (target > arr[end])
    {
        start = end;
        end = end * 2;
    }
    return BinarySearch(arr, start, end, target);
}