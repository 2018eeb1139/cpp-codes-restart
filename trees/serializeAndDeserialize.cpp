string serialize(TreeNode *root)
{
    if (root == NULL)
        return "";
    string ans = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                ans += "#,";
            }
            else
            {
                ans += to_string(curr->val) + ',';
            }
            if (curr != NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
    }
    // cout<<ans;
    return ans;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream ss(data);
    string str;
    getline(ss, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        getline(ss, str, ',');
        if (str == "#")
        {
            curr->left = NULL;
        }
        else
        {
            curr->left = new TreeNode(stoi(str));
            q.push(curr->left);
        }
        getline(ss, str, ',');
        if (str == "#")
        {
            curr->right = NULL;
        }
        else
        {
            curr->right = new TreeNode(stoi(str));
            q.push(curr->right);
        }
    }
    return root;
}