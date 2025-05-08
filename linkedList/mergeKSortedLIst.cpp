ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (t1 && t2)
    {
        if (t1->val < t2->val)
        {
            curr->next = t1;
            curr = t1;
            t1 = t1->next;
        }
        else
        {
            curr->next = t2;
            curr = t2;
            t2 = t2->next;
        }
    }
    if (t1)
    {
        curr->next = t1;
    }
    if (t2)
    {
        curr->next = t2;
    }
    return dummy->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return NULL;
    if (n == 1)
    {
        return lists[0];
    }
    ListNode *head = lists[0];
    for (int i = 1; i < n; i++)
    {
        head = mergeTwoLists(head, lists[i]);
    }
    return head;
}