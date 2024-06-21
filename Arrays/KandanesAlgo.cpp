// Example 1 :

//     Input : nums = [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ] Output : 6 Explanation : The subarray[4, -1, 2, 1] has the largest sum 6.

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible integer value
        int n = nums.size();  // Get the size of the input array

        // Outer loop to fix the starting point of the subarray
        for (int i = 0; i < n; i++)
        {
            // Inner loop to fix the ending point of the subarray
            for (int j = i; j < n; j++)
            {
                int sum = 0; // Initialize sum for the current subarray from i to j

                // Loop to calculate the sum of the subarray from i to j
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k]; // Add the element nums[k] to the sum
                }

                // Update maxSum if the current sum is greater than the current maxSum
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum; // Return the maximum subarray sum found
    }
};

// Optimized Approach

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long maxSum = LONG_MIN; // Initialize maxSum to the smallest possible value
        long long sum = 0;           // Initialize the sum to 0
        int n = nums.size();         // Get the size of the input array

        for (int i = 0; i < n; i++)
        {                   // Loop through each element in the array
            sum += nums[i]; // Add the current element to the sum

            if (sum > maxSum)
            {                 // If the current sum is greater than maxSum
                maxSum = sum; // Update maxSum
            }

            if (sum < 0)
            {            // If the current sum is less than 0
                sum = 0; // Reset the sum to 0
            }
        }

        return maxSum; // Return the maximum subarray sum found
    }
};


// Follow-up question if there are more than one subarray with maximum sum and we have to print every subArray

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}