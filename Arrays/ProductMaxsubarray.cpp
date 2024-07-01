#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/***************************************** Problem Statement *****************************************/
// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product,
// and return the maximum product.

// Example:
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

/***************************************** Approach 1: Using Prefix and Suffix Products *****************************************/
// This approach calculates the product of subarrays using prefix and suffix products.
// Time Complexity: O(N), where N is the size of the array.
// Space Complexity: O(1), as we use constant extra space.

class Solution
{
public:
    int maxProductSubArray(vector<int> &arr)
    {
        int n = arr.size(); // Size of the array

        int pre = 1, suff = 1; // Initialize prefix and suffix product variables
        int ans = INT_MIN;     // Initialize answer to the smallest possible integer value

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1; // Reset pre to 1 if it is 0
            if (suff == 0)
                suff = 1; // Reset suff to 1 if it is 0

            pre *= arr[i];          // Calculate prefix product
            suff *= arr[n - i - 1]; // Calculate suffix product

            ans = max(ans, max(pre, suff)); // Update the answer with the maximum product found
        }
        return ans; // Return the maximum product of any subarray
    }
};

/***************************************** Main Function *****************************************/
int main()
{
    vector<int> nums = {2, 3, -2, 4};

    Solution sol;
    int result = sol.maxProductSubArray(nums);

    cout << "Maximum product of a contiguous subarray: " << result << endl;

    return 0;
}
