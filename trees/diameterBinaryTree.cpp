int solve(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = 1 + max(l, r);
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);
    return temp;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int res = INT_MIN;
    solve(root, res);
    return res;
}