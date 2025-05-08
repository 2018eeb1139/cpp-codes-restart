#include <iostream>
#include <vector>

using namespace std;

int firstOccurence(vector<int> &arr, int target)
{
    int first = -1;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return first;
}

int lastOccurence(vector<int> &arr, int target)
{
    int last = -1;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    return last;
}

int main()
{
    vector<int> arr = {3, 5, 5, 5, 5, 7, 8, 8};
    int target = 5;
    int first = firstOccurence(arr, target);
    int last = lastOccurence(arr, target);
    if (first == -1 || last == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (last - first + 1) << endl;
    }
}
