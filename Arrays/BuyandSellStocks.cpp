// Input : prices = [ 7, 1, 5, 3, 6, 4 ] Output : 5 Explanation : Buy on day 2(price = 1) and sell on day 5(price = 6), profit = 6 - 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include <vector>
#include <algorithm>
                                                                                                                                                                       using namespace std;

class Solution
{
public:
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

// Explanation : Initialization :

//     cpp
//         Copy code int minPrice = prices[0]; // Set the initial minimum price to the first element
// int maxProfit = 0;                          // Initialize maximum profit to 0
// Iterating through prices :

//     cpp
//         Copy code for (int i = 1; i < n; i++)
// {
//     int profit = prices[i] - minPrice;   // Calculate the profit if sold at the current price
//     maxProfit = max(maxProfit, profit);  // Update maximum profit if the current profit is higher
//     minPrice = min(minPrice, prices[i]); // Update the minimum price if the current price is lower
// }
// Return the maximum profit found :

// 
//         Copy code return maxProfit;
// Time and Space Complexity : Time Complexity : 𝑂(𝑛)
// O(n) since we only make a single pass through the array.Space Complexity : O(1) as we use a constant amount of extra space.
