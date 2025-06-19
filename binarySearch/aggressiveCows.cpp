#include <iostream>

using namespace std;

bool func(int minDist, long long positions[], int n, int cows)
{
    int lastPos = -1;
    int cows_ct = cows;
    for (int i = 0; i < n; i++)
    {
        if (positions[i] - lastPos >= minDist || lastPos == -1)
        {
            cows_ct--;
            lastPos = positions[i];
        }
        if (cows_ct == 0)
            break;
    }
    return cows_ct == 0;
}

int main()
{
    int n, cows;
    cin >> n >> cows;
    long long positions[n];
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    sort(positions, positions + n);
    int start = 0;
    int end = 1e9;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (func(mid, positions, n, cows))
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