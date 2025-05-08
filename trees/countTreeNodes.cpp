int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ct1 = countNodes(root->left);
    int ct2 = countNodes(root->right);
    return 1 + ct1 + ct2;
}