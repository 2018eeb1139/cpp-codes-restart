TreeNode *solve(vector<int> &nums, int st, int end)
{
    if (st > end)
        return NULL;
    int mid = st + (end - st) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(nums, st, mid - 1);
    root->right = solve(nums, mid + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return NULL;
    return solve(nums, 0, n - 1);
}