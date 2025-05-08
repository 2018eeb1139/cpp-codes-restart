ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head;
    ListNode *prev = dummy;
    while (curr && curr->next)
    {
        if (curr->val != curr->next->val)
        {
            prev = curr;
            curr = curr->next;
        }
        else
        {
            while (curr->next && curr->val == curr->next->val)
            {
                curr->next = curr->next->next;
            }
            prev->next = curr->next;
            curr = curr->next;
        }
    }
    return dummy->next;
}