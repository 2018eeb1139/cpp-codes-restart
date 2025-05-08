#include <iostream>
#include <vector>
using namespace std;

// return the idx of min Element
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
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
    cout << idx;
}