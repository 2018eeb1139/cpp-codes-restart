int Solution::solve(ListNode *head, int B)
{
    int n = 0;
    ListNode *temp = head;
    while (temp)
    {
        temp = temp->next;
        n++;
    }
    int mid = (n / 2) + 1;
    if (mid <= B)
        return -1;
    else
    {
        temp = head;
        int ct = mid - B - 1;
        while (ct--)
        {
            temp = temp->next;
        }
        return temp->val;
    }
}