/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head); // Use a dummy node to handle edge cases
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // Move fast ahead by n+1 steps to maintain the gap of n nodes between slow and fast
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Now slow is at the node before the one to be deleted
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        // Return the new head
        ListNode *newHead = dummy->next;
        delete dummy; // Free the allocated dummy node
        return newHead;
    }
};
