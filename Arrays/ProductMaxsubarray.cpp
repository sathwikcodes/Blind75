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
