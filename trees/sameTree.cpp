bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p && q == NULL)
        return false;
    if (p == NULL && q)
        return false;
    if (p->val != q->val)
        return false;
    bool ans = isSameTree(p->left, q->left);
    bool ans1 = isSameTree(p->right, q->right);
    return (ans && ans1);
}