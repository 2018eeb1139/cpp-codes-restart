#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<int> &v, int k, int idx, int &ans)
{
    if (v.size() == 0)
    {
        ans = v[0];
        return;
    }
    idx = (idx + k) % v.size();
    v.erase(v.begin() + idx);
    solve(v, k, idx, ans);
    return;
}
int findTheWinner(int n, int k)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    k = k - 1;
    int idx = 0;
    int ans = -1;
    solve(v, k, idx, ans);
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findTheWinner(n, k);
}