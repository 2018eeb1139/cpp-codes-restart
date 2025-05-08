ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeSortedList(ListNode *l1, ListNode *l2)
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
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *middle = findMiddle(head);
    ListNode *left = head;
    ListNode *right = middle->next;
    middle->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeSortedList(left, right);
}