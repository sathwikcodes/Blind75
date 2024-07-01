/***************************************** Naive Approach *****************************************/

/*
    Use a loop to iterate through each number from 0 to n.
    Count the number of 1s in its binary representation using repeated division by 2.
    Time Complexity: O(n * sizeof(integer)), where sizeof(integer) is typically constant.
*/

/***************************************** Solution *****************************************/

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int sum = 0;
            while (num != 0)
            {
                sum += num % 2;
                num = num / 2;
            }
            result.push_back(sum);
        }
        return result;
    }
};

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n * sizeof(integer)), where sizeof(integer) is typically constant.
    Space Complexity: O(n), for storing the result vector.
*/
/***************************************** Better Approach *****************************************/

/*
    Use a previously computed result to optimize counting bits.
    If `i` is even, bits count is the same as `i/2`.
    If `i` is odd, bits count is `i/2` + 1.
    Time Complexity: O(n)
*/

/***************************************** Solution *****************************************/

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> result(n + 1);
        result[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            result[i] = result[i >> 1] + (i & 1);
        }
        return result;
    }
};

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n), as each number up to n is processed once.
    Space Complexity: O(n), for storing the result vector.
*/
/***************************************** Optimal Approach *****************************************/

/*
    Use dynamic programming to compute the number of bits efficiently.
    For each number `i`, the number of 1s in its binary form is `dp[i] = dp[i & (i - 1)] + 1`.
    Time Complexity: O(n)
*/

/***************************************** Solution *****************************************/

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};

/***************************************** Complexity Analysis *****************************************/

/*
    Time Complexity: O(n), as each number up to n is processed once.
    Space Complexity: O(n), for storing the dp array.
*/
