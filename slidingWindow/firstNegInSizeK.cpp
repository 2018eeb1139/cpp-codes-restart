#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    int i = 0, j = 0;
    list<int> l;
    vector<int> ans;
    while (j < arr.size())
    {
        if (arr[j] < 0)
        {
            l.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (l.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(l.front());
                if (arr[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
