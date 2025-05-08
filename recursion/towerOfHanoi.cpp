#include <iostream>

using namespace std;

void solve(int n, int s, int d, int h, int &ct)
{
    ct++;
    if (n == 1)
    {
        cout << "Moving plate " << n << "from " << s << "to " << d << endl;
    }
    solve(n - 1, s, h, d, ct);
    cout << "Moving plate " << n << "from " << s << "to " << d << endl;
    solve(n - 1, h, d, s, ct);
}

int main()
{
    int n;
    cin >> n;
    int ct = 0;
    int s = 1, h = 2, d = 3;
    solve(n, s, d, h, ct);
}