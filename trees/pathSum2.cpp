void solve(TreeNode *root, int targetSum, vector<int> &v, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->val);
    if (root->left == NULL && root->right == NULL && root->val == targetSum)
    {
        ans.push_back(v);
    }
    if (root->left)
    {
        solve(root->left, targetSum - root->val, v, ans);
    }
    if (root->right)
    {
        solve(root->right, targetSum - root->val, v, ans);
    }
    v.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> v;
    solve(root, targetSum, v, ans);
    return ans;
}