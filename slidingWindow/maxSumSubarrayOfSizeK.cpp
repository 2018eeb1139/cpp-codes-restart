#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 5, 1, 8, 2, 9, 1};
    int k = 3;
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MIN;
    while (j < arr.size())
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = max(ans, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << ans;
}
