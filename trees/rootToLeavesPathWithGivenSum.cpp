/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void solve(TreeNode *root, int sum, vector<int> &v, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;

    v.push_back(root->val);

    if (root->left == NULL && root->right == NULL && root->val == sum)
    {
        ans.push_back(v);
    }
    else
    {
        solve(root->left, sum - root->val, v, ans);
        solve(root->right, sum - root->val, v, ans);
    }

    v.pop_back();
}

vector<vector<int>> Solution::pathSum(TreeNode *root, int sum)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(root, sum, v, ans);
    return ans;
}
