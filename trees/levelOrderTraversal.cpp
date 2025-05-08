vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            // cout<<curr->val<<" ";
            v.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        ans.push_back(v);
        v.clear();
    }
    return ans;
}

vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> v;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            // cout<<curr->val<<" ";
            v.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        ans.push_back(v);
        v.clear();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}