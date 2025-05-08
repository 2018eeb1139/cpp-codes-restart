ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || left == right)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *l1 = dummy;
    int cnt = 0;
    while (cnt < left - 1)
    {
        l1 = l1->next;
        cnt++;
    }
    ListNode *t1 = l1->next;
    ListNode *temp = t1;
    ListNode *prev = NULL;
    ListNode *front;
    while (left <= right)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
        left++;
    }
    t1->next = temp;
    l1->next = prev;
    return dummy->next;
}