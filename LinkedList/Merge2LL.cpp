// Naive APPROACH
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> result;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        ListNode *one = list1;
        ListNode *two = list2;
        while (one)
        {
            result.push_back(one->val);
            one = one->next;
        }
        while (two)
        {
            result.push_back(two->val);
            two = two->next;
        }

        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++)
        {

            temp->next = new ListNode(result[i]);
            temp = temp->next;
        }

        return head->next;
    }
};