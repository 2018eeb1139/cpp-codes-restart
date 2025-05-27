#include <iostream>

using namespace std;

bool func(int h, long long trees[], int n, int m)
{
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] > h)
        {
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long trees[n];
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    int start = 0;
    int end = 1e9;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (func(mid, trees, n, m))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans << endl;
}