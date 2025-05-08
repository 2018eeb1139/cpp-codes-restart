ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    int len = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        len++;
        tail = tail->next;
    }
    if (k % len == 0)
        return head;
    k = k % len;
    ListNode *newtail = head;
    for (int i = 0; i < len - k - 1; i++)
    {
        newtail = newtail->next;
    }
    tail->next = head;
    head = newtail->next;
    newtail->next = NULL;
    return head;
}