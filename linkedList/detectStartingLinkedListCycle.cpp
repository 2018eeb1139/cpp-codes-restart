/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode *ptr1 = head;
            ListNode *ptr2 = slow;
            while (ptr1 != ptr2)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }
    return NULL;
}
