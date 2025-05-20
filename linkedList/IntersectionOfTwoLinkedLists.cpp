ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    ListNode *ptr1 = head1;
    ListNode *ptr2 = head2;
    while (ptr1 != ptr2)
    {
        if (ptr1)
        {
            ptr1 = ptr1->next;
        }
        else
        {
            ptr1 = head2;
        }
        if (ptr2)
        {
            ptr2 = ptr2->next;
        }
        else
        {
            ptr2 = head1;
        }
    }
    return ptr1;
}