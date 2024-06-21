// Question : Example 1 :

//     Input : nums = [ 2, 7, 11, 15 ],
//             target = 9 Output : [ 0, 1 ] Explanation : Because nums[0] + nums[1] == 9, we return [ 0, 1 ].

// Naive Approach:

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {-1, -1};
    }
};

// Time Complexity: O(n^2)

// Better Approach :

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;   // Create a map to store numbers and their indices
        int n = nums.size(); // Get the size of the input vector
        for (int i = 0; i < n; i++)
        {                            // Iterate through the vector
            int num = nums[i];       // Get the current number
            int diff = target - num; // Calculate the difference needed to reach the target
            if (mpp.find(diff) != mpp.end())
            {                          // Check if the difference is already in the map
                return {mpp[diff], i}; // If found, return the indices of the complement and the current number
            }
            mpp[num] = i; // Add the current number and its index to the map
        }
        return {-1, -1}; // Return {-1, -1} if no solution is found
    }
};


// approach with example :
First Iteration(i = 0) :

                         cpp Copy code
                         int num = nums[i]; // num = nums[0] = 2
int diff = target - num;                    // diff = 9 - 2 = 7
if (mpp.find(diff) != mpp.end())
{ // mpp.find(7) -> not found since mpp is empty
    // This block is skipped
}
mpp[num] = i; // mpp[2] = 0
// Now mpp = {2: 0}
Second Iteration(i = 1) :

                          cpp Copy code
                          int num = nums[i]; // num = nums[1] = 7
int diff = target - num;                     // diff = 9 - 7 = 2
if (mpp.find(diff) != mpp.end())
{                          // mpp.find(2) -> found, since 2 is in the map
    return {mpp[diff], i}; // return {mpp[2], 1} -> return {0, 1}
}
mpp[num] = i; // This line is not executed because we already returned the result



// Time Complexity: O(n)

// Optimal Approach:

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int n = nums.size();                            // Get the size of the input vector `nums`
        std::vector<std::pair<int, int>> originalindex; // Create a vector to store pairs of (value, original index)

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

// Two - Pointer Technique :

//     First Iteration : cpp
//                           Copy code int left = 0;                 // left points to {2, 0}
// int right = n - 1;                                                // right points to {15, 3}
// int sum = originalindex[left].first + originalindex[right].first; // sum = 2 + 15 = 17
// if (sum > target)
// {
//     right--; // Move the right pointer to the left
// }
// // Now, right points to {11, 2}
// Second Iteration : cpp
//                        Copy code int sum = originalindex[left].first + originalindex[right].first; // sum = 2 + 11 = 13
// if (sum > target)
// {
//     right--; // Move the right pointer to the left
// }
// // Now, right points to {7, 1}
// Third Iteration : cpp
//                       Copy code int sum = originalindex[left].first + originalindex[right].first; // sum = 2 + 7 = 9
// if (sum == target)
// {
//     return {originalindex[left].second, originalindex[right].second}; // Return {0, 1}
// }