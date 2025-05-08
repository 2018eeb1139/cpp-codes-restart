vector<double> averageOfLevels(TreeNode *root)
{
    if (root == NULL)
        return {};
    queue<TreeNode *> q;
    q.push(root);
    vector<double> ans;
    while (!q.empty())
    {
        int sz = q.size();
        vector<double> v;
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
        ans.push_back(accumulate(v.begin(), v.end(), 0.0) / v.size());
    }
    return ans;
}