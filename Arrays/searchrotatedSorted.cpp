#include <iostream>
#include <vector>

using namespace std;

/***************************************** Problem Statement *****************************************/
// Given a rotated sorted array `nums` of distinct integers and a target `target`, return the index of `target` if it is in the array, or -1 if it is not.
// You must write an algorithm with O(log N) runtime complexity.

/***************************************** Approach: Binary Search with Rotated Sorted Array *****************************************/
// This approach uses binary search to efficiently find the target in a rotated sorted array.
// Time Complexity: O(log N), where N is the size of the array `nums`.
// Space Complexity: O(1), as we use only constant extra space.

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size(); // Get the size of the array
        int low = 0;         // Initialize the low pointer
        int high = n - 1;    // Initialize the high pointer

        while (low <= high)
        {                               // Continue until the search space is exhausted
            int mid = (low + high) / 2; // Calculate the middle index

            // If the middle element is the target, return its index
            if (nums[mid] == target)
            {
                return mid;
            }

            // If the left part is sorted
            if (nums[low] <= nums[mid])
            {
                // Check if the target is in the range of the sorted left part
                if (nums[low] <= target && target <= nums[mid])
                {
                    // If so, move the high pointer to mid - 1 to search in the left part
                    high = mid - 1;
                }
                else
                {
                    // Otherwise, move the low pointer to mid + 1 to search in the right part
                    low = mid + 1;
                }
            }
            else
            { // If the right part is sorted
                // Check if the target is in the range of the sorted right part
                if (nums[mid] <= target && target <= nums[high])
                {
                    // If so, move the low pointer to mid + 1 to search in the right part
                    low = mid + 1;
                }
                else
                {
                    // Otherwise, move the high pointer to mid - 1 to search in the left part
                    high = mid - 1;
                }
            }
        }
        return -1; // Return -1 if the target is not found
    }
};

/***************************************** Main Function *****************************************/
int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 1;

    Solution sol;
    int result = sol.search(nums, target);

    if (result != -1)
    {
        cout << "Target " << target << " found at index " << result << endl;
    }
    else
    {
        cout << "Target " << target << " not found in the array" << endl;
    }

    return 0;
}
