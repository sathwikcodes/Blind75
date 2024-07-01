#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

// Problem Statement:
// Find the minimum element in a rotated sorted array.
// Example:
// nums = [4, 5, 6, 7, 0, 1, 2]
// The minimum element is 0.

class Solution
{
public:
    // Optimal Approach:
    // Use binary search to find the minimum element in the rotated sorted array.
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid])
            {
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
            else
            {
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Example:
// nums = [4, 5, 6, 7, 0, 1, 2]
// Let's go through each step to find the minimum element in this rotated sorted array.
// Initialization:
// n = 7 (size of the array)
// ans = INT_MAX
// left = 0
// right = 6

// Iterations:
// First Iteration:
// left = 0, right = 6, mid = (0 + 6) / 2 = 3
// nums[left] = 4, nums[mid] = 7
// Since nums[left] <= nums[mid] (4 <= 7), the left half [4, 5, 6, 7] is sorted.
// Update ans = min(INT_MAX, 4) = 4
// Move to the right half: left = mid + 1 = 4

// Second Iteration:
// left = 4, right = 6, mid = (4 + 6) / 2 = 5
// nums[left] = 0, nums[mid] = 1
// Since nums[left] <= nums[mid] (0 <= 1), the left half [0, 1] is sorted.
// Update ans = min(4, 0) = 0
// Move to the right half: left = mid + 1 = 6

// Third Iteration:
// left = 6, right = 6, mid = (6 + 6) / 2 = 6
// nums[left] = 2, nums[mid] = 2
// Since nums[left] <= nums[mid] (2 <= 2), the left half [2] is sorted.
// Update ans = min(0, 2) = 0
// Move to the right half: left = mid + 1 = 7

// Conclusion:
// At this point, left has moved beyond right (left = 7, right = 6), so the loop terminates.
// The minimum value found is ans = 0.

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Output the result
    cout << "The minimum element is: " << sol.findMin(nums) << endl;

    return 0;
}
