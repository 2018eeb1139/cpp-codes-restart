class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *curr = s.top();
        s.pop();
        if (curr->right)
        {
            pushAll(curr->right);
        }
        return curr->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }

public:
    void pushAll(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
};