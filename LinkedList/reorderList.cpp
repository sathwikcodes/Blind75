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

// Question: Given the head of a singly linked list, reorder the list to be in the following order:
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

// Approach 1: Naive Approach (Using Extra Space)
class Solution1
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        vector<ListNode *> nodes;
        ListNode *current = head;
        while (current)
        {
            nodes.push_back(current);
            current = current->next;
        }

        int left = 0, right = nodes.size() - 1;
        while (left < right)
        {
            nodes[left]->next = nodes[right];
            left++;
            if (left == right)
                break;
            nodes[right]->next = nodes[left];
            right--;
        }
        nodes[left]->next = nullptr;
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N)
};

// Approach 2: Two-Pointer Approach
class Solution2
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // Step 1: Find the middle of the list
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        ListNode *next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Merge the two halves
        ListNode *first = head;
        ListNode *second = prev;
        while (second->next)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(1)
};

// Approach 3: Recursion Approach
class Solution3
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;
        reorderListHelper(nullptr, head);
    }

private:
    bool reorderListHelper(ListNode *&left, ListNode *right)
    {
        if (!right)
            return true;
        bool result = reorderListHelper(left, right->next);
        if (!result)
            return false;
        if (!left)
            left = right;
        if (left->next == right || left == right)
        {
            right->next = nullptr;
            return false;
        }
        ListNode *nextLeft = left->next;
        left->next = right;
        right->next = nextLeft;
        left = nextLeft;
        return true;
    }
    // Time Complexity: O(N), where N is the number of nodes in the list
    // Space Complexity: O(N) due to recursion stack
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
    ListNode *result1 = head;
    sol1.reorderList(result1);
    ListNode *result2 = head;
    sol2.reorderList(result2);
    ListNode *result3 = head;
    sol3.reorderList(result3);

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

    cout << "Approach 1 (Naive Approach): ";
    printList(result1);
    cout << "Approach 2 (Two-Pointer Approach): ";
    printList(result2);
    cout << "Approach 3 (Recursion Approach): ";
    printList(result3);

    return 0;
}
