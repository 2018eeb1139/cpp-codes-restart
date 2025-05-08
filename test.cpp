#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "PAYPALISHIRING";
    int n = 4;
    char v[n + 1][s.size() + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s.size() + 1; j++)
        {
            v[i][j] = '\0';
        }
    }
    int k = 0;
    int i = 0, j = 0;
    while (k < s.size())
    {
        while (i < n)
        {
            v[i][j] = s[k];
            i++;
            k++;
            if (k >= s.size())
                break;
        }
        i = i - 2;
        j = j + 1;
        while (i >= 0)
        {
            v[i][j] = s[k];
            i--;
            j++;
            k++;
            if (k >= s.size())
                break;
        }
        j = j - 1;
        i = i + 2;
        if (k >= s.size())
            break;
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (v[i][j] != '\0')
            {
                cout << v[i][j] << " ";
                ans.push_back(v[i][j]);
            }
        }
        cout << endl;
    }
    cout << ans;
}
