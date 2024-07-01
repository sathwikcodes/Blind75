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

// Question: Reverse a singly linked list and return the head of the reversed list.

// Approach 1: Iterative Approach
class Solution1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next; // Store the next node
            curr->next = prev;               // Reverse the current node's pointer
            prev = curr;                     // Move prev one step forward
            curr = nextNode;                 // Move curr one step forward
        }
        return prev; // Prev will be the new head
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(1)
};

// Approach 2: Recursive Approach
class Solution2
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head; // Base case: if head is null or only one node, it's already reversed
        }
        ListNode *newHead = reverseList(head->next); // Reverse the rest of the list
        head->next->next = head;                     // Make the next node point to the current node
        head->next = nullptr;                        // Set the current node's next to null
        return newHead;                              // New head of the reversed list
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N) due to recursion stack
};

// Approach 3: Using a Stack
class Solution3
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;

        stack<ListNode *> stk;
        ListNode *curr = head;
        while (curr)
        {
            stk.push(curr); // Push all nodes onto the stack
            curr = curr->next;
        }

        ListNode *newHead = stk.top(); // The new head is the last node
        stk.pop();
        curr = newHead;
        while (!stk.empty())
        {
            curr->next = stk.top(); // Pop from the stack and set as the next node
            stk.pop();
            curr = curr->next;
        }
        curr->next = nullptr; // Set the next of the last node to null
        return newHead;
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N) due to the stack
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

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    // Testing all approaches
    ListNode *result1 = sol1.reverseList(head);
    ListNode *result2 = sol2.reverseList(head);
    ListNode *result3 = sol3.reverseList(head);

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

    cout << "Approach 1 (Iterative Approach): ";
    printList(result1);
    cout << "Approach 2 (Recursive Approach): ";
    printList(result2);
    cout << "Approach 3 (Using a Stack): ";
    printList(result3);

    return 0;
}
