#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Question: Given a linked list, determine if it has a cycle in it.

// Approach 1: Using Hash Set (Space Complexity: O(n))
class Solution1
{
public:
    // Function to detect a cycle using an unordered set
    bool hasCycle(ListNode *head)
    {
        // Edge cases: empty list or single node pointing to null
        if (!head || !head->next)
            return false;

        unordered_set<ListNode *> visited; // Hash set to store visited nodes
        ListNode *temp = head;

        // Traverse the linked list
        while (temp != nullptr)
        {
            // If current node is already in the set, cycle detected
            if (visited.find(temp) != visited.end())
            {
                return true;
            }
            // Otherwise, add the node to the set
            visited.insert(temp);
            temp = temp->next;
        }
        // If no cycle found
        return false;
    }
};

// Approach 2: Floyd's Tortoise and Hare (Cycle Detection Algorithm)
class Solution2
{
public:
    // Function to detect a cycle using two pointers
    bool hasCycle(ListNode *head)
    {
        // Edge cases: empty list or single node pointing to null
        if (!head || !head->next)
            return false;

        ListNode *slow = head; // Slow pointer
        ListNode *fast = head; // Fast pointer

        // Traverse the linked list with two pointers
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;       // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps

            // If slow pointer meets fast pointer, cycle detected
            if (slow == fast)
            {
                return true;
            }
        }
        // If no cycle found
        return false;
    }
};

// Approach 3: Modifying ListNode Values (Not recommended for production code)
class Solution3
{
public:
    // Function to detect a cycle by marking visited nodes (not recommended)
    bool hasCycle(ListNode *head)
    {
        // Edge cases: empty list or single node pointing to null
        if (!head || !head->next)
            return false;

        ListNode *temp = head;
        ListNode marker(INT_MIN); // Unique marker node

        // Traverse the linked list
        while (temp != nullptr)
        {
            // If a node points to marker, cycle detected
            if (temp->next == &marker)
            {
                return true;
            }
            // Temporarily mark the node as visited
            ListNode *nextNode = temp->next;
            temp->next = &marker;
            temp = nextNode;
        }
        // If no cycle found
        return false;
    }
};

// Driver code to test the solutions
int main()
{
    // Creating a test linked list with a cycle
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creates a cycle

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    // Testing all approaches
    cout << "Approach 1 (Hash Set): " << (sol1.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;
    cout << "Approach 2 (Tortoise and Hare): " << (sol2.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;
    cout << "Approach 3 (Modifying Values): " << (sol3.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
