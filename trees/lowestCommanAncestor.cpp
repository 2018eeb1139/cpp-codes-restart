TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root == p || root == q)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left && right == NULL)
    {
        return left;
    }
    if (right && left == NULL)
    {
        return right;
    }
    else
    {
        return root;
    }
}