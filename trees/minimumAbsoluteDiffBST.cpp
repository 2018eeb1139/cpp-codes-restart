vector<int> v;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}
int getMinimumDifference(TreeNode *root)
{

    inorder(root);
    int n = v.size();
    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, v[i] - v[i - 1]);
    }
    return ans;
}