/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode *Solution::sortedListToBST(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        return new TreeNode(head->val);
    }
    ListNode *prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val); // mid
    prev->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}
