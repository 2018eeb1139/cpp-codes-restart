vector<vector<int>> ans;
void solve(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    v.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(v);
        return;
    }
    if (root->left)
    {
        solve(root->left, v);
        v.pop_back();
    }
    if (root->right)
    {
        solve(root->right, v);
        v.pop_back();
    }
}
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    vector<int> v;
    solve(root, v);
    for (int i = 0; i < ans.size(); i++)
    {
        int res = 0;
        for (int j = 0; j < ans[i].size(); j++)
        {
            res = (res * 10) + ans[i][j];
        }
        sum += res;
    }
    return sum;
}