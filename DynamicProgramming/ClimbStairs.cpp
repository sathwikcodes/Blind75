#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Question: You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Approach 1: Recursion (Exponential Time Complexity)
class Solution1
{
public:
    // Recursive function to calculate the number of ways to climb stairs
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1; // Base cases: 0 steps or 1 step
        }
        // Recursive calls for (n-1) and (n-2) steps
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Approach 2: Memoization (Top-down Dynamic Programming)
class Solution2
{
public:
    // Recursive function with memoization
    int climbStairs(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
        {
            return 1; // Base cases: 0 steps or 1 step
        }
        // Check if result for 'n' is already memoized
        if (memo.find(n) == memo.end())
        {
            // Memoize the result of (n-1) + (n-2) steps
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }
        return memo[n];
    }

    // Wrapper function to initiate memoization and call the recursive function
    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
};

// Approach 3: Tabulation (Bottom-up Dynamic Programming)
class Solution3
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1; // Base cases: 0 steps or 1 step
        }

        vector<int> dp(n + 1); // DP array to store number of ways for each step
        dp[0] = dp[1] = 1;     // Base cases initialization

        // Fill DP array iteratively from 2 to n
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // Sum of ways from (i-1) and (i-2) steps
        }

        return dp[n]; // Return number of ways to reach nth step
    }
};

// Approach 4: Space Optimization (Optimized Bottom-up DP)
class Solution4
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1; // Base cases: 0 steps or 1 step
        }

        int prev = 1, curr = 1; // Initialize variables for optimized space
        for (int i = 2; i <= n; i++)
        {
            int temp = curr;    // Store current value
            curr = prev + curr; // Update current value with sum of previous two
            prev = temp;        // Update previous value with previous current
        }

        return curr; // Return number of ways to reach nth step
    }
};

// Driver code to test the solutions
int main()
{
    int n = 5; // Example input for number of stairs
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    Solution4 sol4;

    // Testing all approaches
    cout << "Approach 1 (Recursion): " << sol1.climbStairs(n) << endl;
    cout << "Approach 2 (Memoization): " << sol2.climbStairs(n) << endl;
    cout << "Approach 3 (Tabulation): " << sol3.climbStairs(n) << endl;
    cout << "Approach 4 (Space Optimization): " << sol4.climbStairs(n) << endl;

    return 0;
}
