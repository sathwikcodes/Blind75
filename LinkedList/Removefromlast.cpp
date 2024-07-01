#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Question: Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Approach 1: Two-Pointer Approach
class Solution1
{
public:
    // Function to remove the nth node from the end using two pointers
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
    // Time Complexity: O(L), where L is the length of the linked list
    // Space Complexity: O(1)
};

// Approach 2: Calculate Length Approach
class Solution2
{
public:
    // Function to remove the nth node from the end by calculating the length
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *temp = head;

        // Calculate the length of the list
        int length = 0;
        while (temp != nullptr)
        {
            length++;
            temp = temp->next;
        }

        // Find the node just before the one to be deleted
        temp = dummy;
        for (int i = 0; i < length - n; i++)
        {
            temp = temp->next;
        }

        // Delete the nth node from the end
        ListNode *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        // Return the new head
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    // Time Complexity: O(L), where L is the length of the linked list
    // Space Complexity: O(1)
};

// Approach 3: Stack Approach
class Solution3
{
public:
    // Function to remove the nth node from the end using a stack
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode *> st;
        ListNode *current = dummy;

        // Push all nodes onto the stack
        while (current != nullptr)
        {
            st.push(current);
            current = current->next;
        }

        // Pop n nodes from the stack
        for (int i = 0; i < n; i++)
        {
            st.pop();
        }

        // The next node of the top node is the one to be deleted
        ListNode *prev = st.top();
        ListNode *toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;

        // Return the new head
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    // Time Complexity: O(L), where L is the length of the linked list
    // Space Complexity: O(L) for the stack
};

// Driver code to test the solutions
int main()
{
    // Creating a test linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    // Testing all approaches
    ListNode *result1 = sol1.removeNthFromEnd(head, n);
    ListNode *result2 = sol2.removeNthFromEnd(head, n);
    ListNode *result3 = sol3.removeNthFromEnd(head, n);

    // Print results
    auto printList = [](ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    };

    cout << "Approach 1 (Two-Pointer Approach): ";
    printList(result1);
    cout << "Approach 2 (Calculate Length Approach): ";
    printList(result2);
    cout << "Approach 3 (Stack Approach): ";
    printList(result3);

    return 0;
}
