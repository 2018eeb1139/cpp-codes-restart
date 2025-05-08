bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == targetSum)
            return true;
    }
    bool ans = hasPathSum(root->left, targetSum - root->val);
    bool ans1 = hasPathSum(root->right, targetSum - root->val);

    return (ans || ans1);
}