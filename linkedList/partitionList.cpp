ListNode *partition(ListNode *head, int x)
{
    if (head == NULL)
        return NULL;
    ListNode *temp = head;
    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-2);
    ListNode *head2 = l1;
    ListNode *head3 = l2;
    while (temp)
    {
        if (temp->val >= x)
        {
            l2->next = new ListNode(temp->val);
            l2 = l2->next;
        }
        else
        {
            l1->next = new ListNode(temp->val);
            l1 = l1->next;
        }
        temp = temp->next;
    }
    l1->next = head3->next;
    return head2->next;
}