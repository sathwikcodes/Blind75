#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Question:
// Best Time to Buy and Sell Stock
// Input: prices = [7, 1, 5, 3, 6, 4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

class Solution
{
public:
    // Naive Approach:
    // Check every possible pair of buy and sell days.
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int maxProfitNaive(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;

        // Check every pair of buy and sell days
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Calculate profit
                int profit = prices[j] - prices[i];
                // Update maximum profit
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }

    // Better Approach:
    // Use an array to store the maximum price from current day to the end.
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int maxProfitBetter(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        // Array to store the maximum price from current day to the end
        vector<int> maxPriceFromRight(n);
        maxPriceFromRight[n - 1] = prices[n - 1];

        // Fill the array with the maximum prices from the right
        for (int i = n - 2; i >= 0; i--)
        {
            maxPriceFromRight[i] = max(maxPriceFromRight[i + 1], prices[i]);
        }

        int maxProfit = 0;

        // Calculate the maximum profit
        for (int i = 0; i < n; i++)
        {
            int profit = maxPriceFromRight[i] - prices[i];
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }

    // Optimal Approach:
    // Track the minimum price seen so far and calculate profit for each day.
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        int minPrice = prices[0]; // Minimum price seen so far
        int maxProfit = 0;        // Maximum profit seen so far

        for (int i = 1; i < n; i++)
        {
            // Calculate the profit if we sell at the current price
            int profit = prices[i] - minPrice;

            // Update the maximum profit
            maxProfit = max(maxProfit, profit);

            // Update the minimum price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Output the results from different approaches
    cout << "Naive Approach: " << sol.maxProfitNaive(prices) << endl;
    cout << "Better Approach: " << sol.maxProfitBetter(prices) << endl;
    cout << "Optimal Approach: " << sol.maxProfit(prices) << endl;

    return 0;
}
