/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;

    return temp;
}
