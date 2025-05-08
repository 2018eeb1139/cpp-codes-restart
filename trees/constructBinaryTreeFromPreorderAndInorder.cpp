TreeNode *solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &m)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = m[root->val];
    int numsLeft = inRoot - inStart;
    root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
    root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() != inorder.size())
        return NULL;
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    return solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
}