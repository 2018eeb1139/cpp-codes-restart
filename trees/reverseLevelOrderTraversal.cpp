/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode *root)
{
    vector<vector<int>> res;
    vector<int> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    vector<int> v;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            TreeNode *curr = q.front();
            q.pop();
            v.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        res.push_back(v);
        v.clear();
    }
    int n = res.size();
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> &v1 = res[i];
        for (int &x : v1)
        {
            ans.push_back(x);
        }
    }
    return ans;
}
