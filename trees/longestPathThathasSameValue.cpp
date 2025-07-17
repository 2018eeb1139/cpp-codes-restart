int mx = 0;

int dfs(TreeNode *root)
{
    if (!root)
        return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    int leftPath = 0, rightPath = 0;

    if (root->left && root->left->val == root->val)
    {
        leftPath = left + 1;
    }
    if (root->right && root->right->val == root->val)
    {
        rightPath = right + 1;
    }

    // Path through root = leftPath + rightPath
    mx = max(mx, leftPath + rightPath);

    // Return longest one-way path to parent
    return max(leftPath, rightPath);
}

int longestUnivaluePath(TreeNode *root)
{
    dfs(root);
    return mx;
}
