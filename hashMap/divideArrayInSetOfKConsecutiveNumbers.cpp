// same as hand of straights

bool isPossibleDivide(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n % k != 0)
        return false;
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] += 1;
    }
    while (!mp.empty())
    {
        int start = mp.begin()->first;
        for (int i = 0; i < k; i++)
        {
            if (mp.find(start + i) == mp.end())
            {
                return false;
            }
            else
            {
                mp[start + i]--;
                if (mp[start + i] == 0)
                {
                    mp.erase(start + i);
                }
            }
        }
    }
    return true;
}