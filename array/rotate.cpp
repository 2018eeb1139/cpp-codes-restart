#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[(i + k) % n] = arr[i];
    }
    arr = ans;
}

void rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k %= n;                                // Handle cases where k > n
    reverse(arr.begin(), arr.end());       // Reverse the whole array
    reverse(arr.begin(), arr.begin() + k); // Reverse first k elements
    reverse(arr.begin() + k, arr.end());   // Reverse the remaining elements
}