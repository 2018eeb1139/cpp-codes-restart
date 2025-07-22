ListNode *reverse(ListNode *head)
{
    ListNode *front;
    ListNode *temp = head;
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
void reorderList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *rev = reverse(slow);
    ListNode *curr = head;
    while (rev->next)
    {
        ListNode *tempcurr = curr->next;
        ListNode *temprev = rev->next;
        curr->next = rev;
        rev->next = tempcurr;
        curr = tempcurr;
        rev = temprev;
    }
}