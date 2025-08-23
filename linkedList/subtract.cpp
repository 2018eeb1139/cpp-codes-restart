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
    ListNode *prev = NULL;
    ListNode *temp = head;
    ListNode *front;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *Solution::subtract(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *secondHalf = reverse(slow->next);
    ListNode *first = head;
    ListNode *second = secondHalf;

    while (second)
    {
        first->val = (second->val) - (first->val);
        second = second->next;
        first = first->next;
    }

    slow->next = reverse(secondHalf);

    return head;
}
