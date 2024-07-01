#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

// Problem Statement:
// Given an integer array nums, return true if any value appears at least twice in the array,
// and return false if every element is distinct.

// Example:
// Example 1: Input: nums = [1, 2, 3, 1] Output: true. Explanation: 1 appeared two times in the input array.
// Example 2: Input: nums = [1, 2, 3, 4] Output: false Explanation: input array does not contain any duplicate number.

class Solution
{
public:
    // Naive Approach:
    // Use two nested loops to check for any duplicates.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    bool containsDuplicateNaive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Better Approach:
    // Sort the array and check for adjacent duplicates.
    // Time Complexity: O(n log n)
    // Space Complexity: O(1)
    bool containsDuplicateBetter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int index = 1; index < nums.size(); index++)
        {
            if (nums[index] == nums[index - 1])
            {
                return true;
            }
        }
        return false;
    }

    // Optimal Approach:
    // Use a hash set to track seen elements.
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    bool containsDuplicateOptimal(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.find(num) != seen.end())
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    // Output the results from different approaches
    cout << "Naive Approach: " << (sol.containsDuplicateNaive(nums) ? "true" : "false") << endl;
    cout << "Better Approach: " << (sol.containsDuplicateBetter(nums) ? "true" : "false") << endl;
    cout << "Optimal Approach: " << (sol.containsDuplicateOptimal(nums) ? "true" : "false") << endl;

    return 0;
}
