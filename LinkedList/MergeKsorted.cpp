#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Question: Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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

// Approach 1: Naive Approach
// Explanation: This approach merges k sorted linked lists by putting all elements into a vector, sorting the vector, and then creating a new sorted linked list from the sorted vector.
// Time Complexity: O(N log N), where N is the total number of nodes in all k lists combined. Sorting the vector takes O(N log N) time.
// Space Complexity: O(N), where N is the total number of nodes in all k lists combined. Extra space is used for the vector to store all elements.
class Solution1
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> result;
        for (auto l : lists)
        {
            while (l)
            {
                result.push_back(l->val);
                l = l->next;
            }
        }
        sort(result.begin(), result.end());
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        for (int val : result)
        {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        return dummy->next;
    }
};

// Approach 2: Merge with Divide and Conquer
// Explanation: This approach divides the k lists into pairs, merges each pair, and continues this process until one list remains.
// Time Complexity: O(N log k), where N is the total number of nodes and k is the number of lists. Merging two lists takes O(N) and this process is done log k times.
// Space Complexity: O(1) for the iterative approach, but O(log k) due to recursion stack if implemented recursively.
class Solution2
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int interval = 1;
        while (interval < lists.size())
        {
            for (int i = 0; i + interval < lists.size(); i += interval * 2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};

// Approach 3: Using a Min-Heap (Priority Queue)
// Explanation: This approach uses a min-heap to always extract the smallest element from the k lists, ensuring the final list is sorted.
// Time Complexity: O(N log k), where N is the total number of nodes and k is the number of lists. Each insertion and extraction from the heap takes O(log k) time.
// Space Complexity: O(k), where k is the number of lists. Extra space is used for the heap.
class Solution3
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto compare = [](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> pq(compare);

        for (auto l : lists)
        {
            if (l)
                pq.push(l);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (!pq.empty())
        {
            ListNode *smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next)
                pq.push(smallest->next);
        }

        return dummy->next;
    }
    // Time Complexity: O(N log k), where N is the total number of nodes in all lists and k is the number of lists
    // Space Complexity: O(k) for the heap
};

// Driver code to test the solutions
int main()
{
    // Create example lists
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    // Test each solution
    ListNode *result1 = sol1.mergeKLists(lists);
    ListNode *result2 = sol2.mergeKLists(lists);
    ListNode *result3 = sol3.mergeKLists(lists);

    // Function to print the linked list
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

    cout << "Approach 2 (Merge with Divide and Conquer): ";
    printList(result2);

    cout << "Approach 3 (Using a Min-Heap): ";
    printList(result3);

    return 0;
}
