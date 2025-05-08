#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int start, int end, int target)
{
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return res;
}

// same as finding an element in infinite sorted array just
// mixup of First occurence of element in sorted array and finding an element in infinite sorted array
int main()
{
    int start = 0;
    int end = 1;
    int target = 1;
    vector<int> arr;
    while (target > arr[end])
    {
        start = end;
        end = end * 2;
    }
    return BinarySearch(arr, start, end, target);
}