class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return head;
    unordered_map<Node *, Node *> mp;
    Node *temp = head;
    while (temp)
    {
        Node *newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        Node *copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}