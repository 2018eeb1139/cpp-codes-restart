
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            v.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        if (flag == 0)
        {
            ans.push_back(v);
            v.clear();
            flag = 1;
        }
        else
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            v.clear();
            flag = 0;
        }
    }
    return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool flag = false; // Use boolean for clarity

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v(sz); // Preallocate size for direct indexing

        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            // Insert in normal or reversed order
            int index = flag ? (sz - 1 - i) : i;
            v[index] = curr->val;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        ans.push_back(v);
        flag = !flag; // Toggle flag
    }
    return ans;
}
