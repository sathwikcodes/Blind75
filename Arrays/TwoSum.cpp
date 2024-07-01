/***************************************** Problem Statement *****************************************/

/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.

    Example:
    Input: nums = [2, 7, 11, 15], target = 9
    Output: [0, 1]
    Explanation: nums[0] + nums[1] == 9, so we return [0, 1].
*/

/***************************************** Naive Approach *****************************************/

/*
    Use a nested loop to check every pair of numbers in the array.
    Time Complexity: O(n^2)
*/

/***************************************** Solution *****************************************/

#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size(); // Get the size of the input vector `nums`

        // Iterate through the vector with two nested loops
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Check if the sum of the current pair equals the target
                if (nums[i] + nums[j] == target)
                {
                    return {i, j}; // Return the indices of the two numbers
                }
            }
        }

        // If no such pair is found, return {-1, -1}
        return {-1, -1};
    }
};

/***************************************** Example Usage *****************************************/

/*
    Example:
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    // Output: [0, 1]
*/

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n^2), due to the nested loops iterating through all pairs.
    Space Complexity: O(1), as no extra space is used other than the input and output vectors.
*/
/***************************************** Better Approach *****************************************/

/*
    Use a hash map to store each number and its index as we iterate through the array.
    For each number `num` in the array, compute `diff = target - num`.
    Check if `diff` exists in the hash map.
    Time Complexity: O(n), Space Complexity: O(n)
*/

/***************************************** Solution *****************************************/

#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> numMap; // Map to store numbers and their indices

        // Iterate through the vector
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];       // Current number in the vector
            int diff = target - num; // Calculate the difference needed to reach the target

            // Check if the difference exists in the map
            if (numMap.find(diff) != numMap.end())
            {
                return {numMap[diff], i}; // Return indices of the current number and its complement
            }

            numMap[num] = i; // Add current number and its index to the map
        }

        // If no such pair is found, return {-1, -1}
        return {-1, -1};
    }
};

/***************************************** Example Usage *****************************************/

/*
    Example:
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    // Output: [0, 1]
*/

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n), as each lookup and insertion operation in the hash map takes average O(1) time.
    Space Complexity: O(n), for the hash map storing up to `n` elements.
*/
/***************************************** Optimal Approach *****************************************/

/*
    Sort the array and use two pointers to find two numbers that add up to the target.
    Time Complexity: O(n log n) for sorting + O(n) for two-pointer traversal = O(n log n)
    Space Complexity: O(n), for storing the original indices.
*/

/***************************************** Solution *****************************************/

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size();                            // Get the size of the input vector `nums`
        std::vector<std::pair<int, int>> originalindex; // Vector of pairs to store (value, original index)

        // Fill the `originalindex` vector with pairs of (value, original index)
        for (int i = 0; i < n; i++)
        {
            originalindex.emplace_back(nums[i], i);
        }

        // Sort the `originalindex` vector based on the values (the first element of the pairs)
        std::sort(originalindex.begin(), originalindex.end());

        // Initialize two pointers
        int left = 0;      // Start pointer at the beginning of the sorted vector
        int right = n - 1; // Start pointer at the end of the sorted vector

        // Use the two-pointer technique to find the two numbers that add up to the target
        while (left < right)
        {
            int sum = originalindex[left].first + originalindex[right].first; // Calculate the sum of the values at the two pointers

            // If the sum equals the target, return the original indices of the two numbers
            if (sum == target)
            {
                return {originalindex[left].second, originalindex[right].second};
            }
            // If the sum is less than the target, move the left pointer to the right
            else if (sum < target)
            {
                left++;
            }
            // If the sum is greater than the target, move the right pointer to the left
            else if (sum > target)
            {
                right--;
            }
        }

        // If no such pair is found, return {-1, -1}
        return {-1, -1};
    }
};

/***************************************** Example Usage *****************************************/

/*
    Example:
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    // Output: [0, 1]
*/

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n log n) for sorting + O(n) for two-pointer traversal, resulting in O(n log n) overall.
    Space Complexity: O(n), for the vector of pairs `originalindex`.
*/
