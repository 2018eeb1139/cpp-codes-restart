unordered_map<Node *, Node *> mp;
void dfs(Node *node)
{
    Node *copy = new Node(node->val);
    mp[node] = copy;
    for (auto child : node->neighbors)
    {
        if (mp.find(child) != mp.end())
        {
            copy->neighbors.push_back(mp[child]);
        }
        else
        {
            dfs(child);
            copy->neighbors.push_back(mp[child]);
        }
    }
}
Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;
    dfs(node);
    return mp[node];
}