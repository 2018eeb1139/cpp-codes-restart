const long long INF = 1e12;
bool solve(TreeNode *root, long long mn, long long mx)
{
    if (root == NULL)
        return true;
    if (root->val >= mx || root->val <= mn)
        return false;
    bool ans = solve(root->left, mn, root->val);
    bool ans1 = solve(root->right, root->val, mx);

    return (ans && ans1);
}
bool isValidBST(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    return solve(root, -INF, INF);
}