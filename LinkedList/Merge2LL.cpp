#include <iostream>
#include <vector>
#include <algorithm>
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

// Question: Merge two sorted linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.

// Approach 1: Naive Approach
class Solution1
{
public:
    // Function to merge two lists using an intermediate vector and sorting it
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> result;
        ListNode *one = list1;
        ListNode *two = list2;

        // Push all elements of list1 into the vector
        while (one)
        {
            result.push_back(one->val);
            one = one->next;
        }

        // Push all elements of list2 into the vector
        while (two)
        {
            result.push_back(two->val);
            two = two->next;
        }

        // Sort the vector
        sort(result.begin(), result.end());

        // Create a new sorted linked list from the sorted vector
        ListNode *head = new ListNode(0); // Dummy node
        ListNode *temp = head;
        for (int i = 0; i < result.size(); i++)
        {
            temp->next = new ListNode(result[i]);
            temp = temp->next;
        }

        return head->next; // Return the next node of dummy node as the new head
    }
    // Time Complexity: O(n log n) due to sorting
    // Space Complexity: O(n) for the intermediate vector
};

// Approach 2: Iterative Approach
class Solution2
{
public:
    // Function to merge two lists iteratively
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to simplify edge cases
        ListNode *current = dummy;

        // Traverse both lists and append the smaller value to the new list
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Append the remaining nodes of the non-empty list
        if (list1 != nullptr)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }

        return dummy->next; // Return the next node of dummy node as the new head
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
};

// Approach 3: Recursive Approach
class Solution3
{
public:
    // Function to merge two lists recursively
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Base cases: if one of the lists is empty, return the other list
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // Compare the values of the current nodes and recursively merge the rest
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to recursion stack
};

// Driver code to test the solutions
int main()
{
    // Creating test linked lists
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    // Testing all approaches
    ListNode *result1 = sol1.mergeTwoLists(list1, list2);
    ListNode *result2 = sol2.mergeTwoLists(list1, list2);
    ListNode *result3 = sol3.mergeTwoLists(list1, list2);

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
    cout << "Approach 2 (Iterative Approach): ";
    printList(result2);
    cout << "Approach 3 (Recursive Approach): ";
    printList(result3);

    return 0;
}
