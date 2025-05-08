#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 8, 10, 15};
    int target = 12;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return min(abs(arr[end] - target), abs(arr[start] - target));
}