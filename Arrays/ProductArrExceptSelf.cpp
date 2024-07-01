#include <vector>
#include <iostream>

using namespace std;

/***************************************** Approach 1 *****************************************/
// Problem Statement:
// Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to
// the product of all the elements of nums except nums[i].
// Example:
// Input: [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Brute Force Approach
// Time Complexity: O(N^2), Where N is the size of the Array(nums). Here Two nested loop creates the time complexity.
// Space complexity: O(1), Constant space. Extra space is only allocated for the Array(output), however the output does not count towards the space complexity.
// Note: This will give TLE.

class Solution1
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output;
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};

/***************************************** Approach 2 *****************************************/
// Dynamic Programming Approach (Tabulation)
// Time Complexity: O(N), As we iterate the Array(nums) thrice. Where N = size of the array.
// Space complexity: O(N), Array(left_Product and right_Product) space.

class Solution2
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for (int i = 1; i < n; i++)
        {
            left_Product[i] = left_Product[i - 1] * nums[i - 1];
        }
        right_Product[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right_Product[i] = right_Product[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};

/***************************************** Approach 3 *****************************************/
// Optimized Approach
// Time Complexity: O(N), As we iterate the Array(nums) twice. Where N = size of the array.
// Space complexity: O(1), Constant space. Extra space is only allocated for the Array(output), however the output does not count towards the space complexity.

class Solution3
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for (int i = 1; i < n; i++)
        {
            output[i] = output[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    Solution1 sol1;
    vector<int> result1 = sol1.productExceptSelf(nums);
    cout << "Approach 1 (Brute Force): ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    Solution2 sol2;
    vector<int> result2 = sol2.productExceptSelf(nums);
    cout << "Approach 2 (Dynamic Programming - Tabulation): ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    Solution3 sol3;
    vector<int> result3 = sol3.productExceptSelf(nums);
    cout << "Approach 3 (Optimized): ";
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
