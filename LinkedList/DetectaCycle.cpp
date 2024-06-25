/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *temp = head;
        if (!head || !head->next)
            return false;
        unordered_set<ListNode *> mpp;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return true;
            }
            else
            {
                mpp.insert(temp);
            }
            temp = temp->next;
        }
        return false;
    }
};