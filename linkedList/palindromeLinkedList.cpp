/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *head)
{
    ListNode *front;
    ListNode *prev = NULL;
    ListNode *temp = head;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int Solution::lPalin(ListNode *head)
{
    if (!head || !head->next)
        return 1;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;

    ListNode *t1 = head;
    ListNode *t2 = reverse(slow);
    while (t1 && t2)
    {
        if (t1->val != t2->val)
        {
            return 0;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return 1;
}
