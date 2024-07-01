/***************************************** Problem Statement *****************************************/

/*
    Given an array nums of n integers, find all unique triplets in the array which gives the sum of zero.
    Note: The solution set must not contain duplicate triplets.

    Example:
    Input: nums = [-1, 0, 1, 2, -1, -4]
    Output: [[-1, -1, 2], [-1, 0, 1]]

    Explanation: The solution set contains two triplets [-1, 0, 1] and [-1, -1, 2].
*/

/***************************************** Approach *****************************************/

/*
    1. Sort the input array nums.
    2. Iterate through the array, considering each element as the potential first element of a triplet.
    3. Use two-pointer technique to find pairs that sum to -nums[i].
    4. Avoid duplicates in the result by skipping duplicate elements and adjusting pointers appropriately.
    5. Return the list of unique triplets that sum up to zero.
*/

/***************************************** Solution *****************************************/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Step 1: Sort the input array
        sort(nums.begin(), nums.end());
        // Now nums = [-4, -1, -1, 0, 1, 2]

        int n = nums.size();

        // Step 2: Initialize an empty vector to store the result
        vector<vector<int>> ans;

        // Step 3: Iterate through the array, considering each element as the potential first element of a triplet
        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements to avoid duplicate triplets in the result
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 4: Use two-pointer technique to find pairs that sum to -nums[i]
            int j = i + 1;
            int k = n - 1;

            // While the two pointers do not cross
            while (j < k)
            {
                // Calculate the sum of the current triplet
                int sum = nums[i] + nums[j] + nums[k];

                // If the sum is less than zero, move the left pointer to the right
                if (sum < 0)
                {
                    j++;
                }
                // If the sum is greater than zero, move the right pointer to the left
                else if (sum > 0)
                {
                    k--;
                }
                // If the sum is zero, we found a valid triplet
                else
                {
                    // Store the triplet in the result
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    // Move both pointers to the next different elements to avoid duplicates
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        // Step 5: Return the list of triplets
        return ans;
    }
};

/***************************************** Example Usage *****************************************/

/*
    Example:
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);
    // Output: [[-1, -1, 2], [-1, 0, 1]]
*/

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(N^2), where N is the size of the input array nums. Sorting takes O(N log N) time, and each iteration through the array using two pointers takes O(N).
    Space Complexity: O(N), for storing the output vector of triplets.
*/
