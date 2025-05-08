#include <iostream>
#include <vector>
#include <math>
using namespace std;

bool isValid(vector<int> &arr, int n, int k, int mid)
{
    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            students++;
            sum = arr[i];
        }
    }
    if (students > k)
        return false;
    return true;
}
int findPages(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    if (n < k)
        return -1;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (k == 1)
        return sum;

    int start = *max_element(arr.begin(), arr.end());
    int end = sum;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}