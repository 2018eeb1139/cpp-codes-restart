int subarraySum(vector<int> &arr, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = 0;
    int ct = 0;
    while (j < arr.size())
    {
        sum += arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            ct++;
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
            {
                mx = max(mx, j - i + 1);
                if (j >= i)
                    ct++;
            }
            j++;
        }
    }
    return {ct, mx};
}

// for negative numbers
// prefix_sum + hashing hard

int longestSubarray(vector<int> &arr, int k)
{
    // code here
    unordered_map<long long, int> mp; // prefixSum -> first index
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // Case 1: subarray from 0 to i
        if (sum == k)
        {
            maxLen = i + 1;
        }

        // Case 2: subarray ending at i
        if (mp.find(sum - k) != mp.end())
        {
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        // Store first occurrence only
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }

    return maxLen;
}
