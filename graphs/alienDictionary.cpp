string findOrder(vector<string> &words)
{
    // code here
    int n = words.size();
    vector<int> indegree(26, 0);
    vector<int> adj[26];
    vector<bool> present(26, 0);

    for (auto &word : words)
    {
        for (char c : word)
        {
            present[c - 'a'] = true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        string s1 = words[i - 1];
        string s2 = words[i];
        int j = 0, k = 0;
        while (j < s1.size() && k < s2.size())
        {
            if (s1[j] == s2[k])
            {
                j++;
                k++;
            }
            else if (s1[j] != s2[k])
            {
                adj[s1[j] - 'a'].push_back(s2[k] - 'a');
                indegree[s2[k] - 'a']++;
                break;
            }
        }
        if (j == s2.size() && s1.size() > s2.size())
            return "";
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (present[i] && indegree[i] == 0)
        {
            q.push(i);
        }
    }
    string ans = "";
    while (!q.empty())
    {
        int curr = q.front();
        ans.push_back(curr + 'a');
        q.pop();
        for (int &child : adj[curr])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    // cout<<ans;
    // return ans;
    // for(int i=0;i<26;i++){
    //     if(indegree[i] != 0){
    //         return "false";
    //     }
    // }
    // return "true";
    int total_present = count(present.begin(), present.end(), true);
    if (ans.size() != total_present)
        return "";
    return ans;
}