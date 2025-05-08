vector<int> ans;
void solve(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        ans.push_back(root->val);
    }
    solve(root->right, level + 1);
    solve(root->left, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
        return {};
    solve(root, 0);
    return ans;
}