#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
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

int reverseBinarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
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

int main()
{
    vector<int> arr = {9, 6, 4, 2, 1};
    // order of the array is not known whether is is sorted in increasing order or decreasing.
    int target = 4;
    if (arr[0] < arr[1])
    {
        return BinarySearch(arr, target);
    }
    else
    {
        return reverseBinarySearch(arr, target);
    }
}