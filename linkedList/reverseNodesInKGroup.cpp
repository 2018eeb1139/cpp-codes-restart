struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getKthNode(ListNode *temp, int k)
{
    k = k - 1;
    while (temp && k)
    {
        temp = temp->next;
        k = k - 1;
    }
    return temp;
}
ListNode *reverse(ListNode *temp)
{
    ListNode *front;
    ListNode *prev = NULL;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prev;
    ListNode *nextNode;
    while (temp)
    {
        ListNode *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            prev->next = temp;
            break;
        }
        ListNode *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prev->next = kthNode;
        }
        prev = temp;
        temp = nextNode;
    }
    return head;
}