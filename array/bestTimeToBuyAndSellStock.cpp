#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int ans = 0;
    int buy = prices[0];
    for (int i = 1; i < n; i++)
    {
        int sell = prices[i];
        if (sell < buy)
        {
            buy = sell;
        }
        else if (sell > buy)
        {
            ans = max(ans, sell - buy);
        }
    }
    return ans;
}