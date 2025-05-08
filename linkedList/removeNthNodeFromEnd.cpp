ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;
    ListNode *dummy = new ListNode();
    ListNode *fast = dummy;
    ListNode *slow = dummy;
    dummy->next = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}