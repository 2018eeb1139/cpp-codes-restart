int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    1 2 3

        int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return 1 + max(l, r);
}

// min Depth little tricky
int Solution::minDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (root->left == NULL || root->right == NULL)
    {
        return 1 + max(l, r);
    }
    return 1 + min(l, r);
}