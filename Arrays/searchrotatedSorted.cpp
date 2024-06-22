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

// Example : arr = [ 4, 5, 6, 7, 0, 1, 2 ], k = 1 Let's go through the code execution step-by-step for this example.

//                                          Initial State : arr = [ 4, 5, 6, 7, 0, 1, 2 ] n = 7 k = 1 low = 0 high = 6 First Iteration : Calculate mid = (0 + 6) / 2 = 3 arr[mid] = arr[3] = 7 Since arr[mid] != k,
//           we proceed to check the sorted part.Check if the left part is sorted : arr[low] <= arr[mid] = > 4 <= 7, which is true.Check if k is in the left sorted part : arr[low] <= k &&k <= arr[mid] = > 4 <= 1 && 1 <= 7, which is false.So, we move to the right part : low = mid + 1 = 4 Second Iteration : Calculate mid = (4 + 6) / 2 = 5 arr[mid] = arr[5] = 1 Since arr[mid] == k, we return mid = 5 The target element 1 is found at index 5.

//                                                                                                                                                                                                                                                                                                                                                                                            Visual Breakdown Here’s a visual breakdown of each iteration :

//     First Iteration :

//     Array : [ 4, 5, 6, 7, 0, 1, 2 ] Indices : 0 1 2 3 4 5 6 Low : 0,
//           High : 6, Mid : 3 Middle element : 7 The left part[4, 5, 6, 7] is sorted.1 is not in[4, 5, 6, 7], so move to the right part.New Low : 4 Second Iteration :

//     Array : [ 4, 5, 6, 7, 0, 1, 2 ] Indices : 0 1 2 3 4 5 6 Low : 4,
//           High : 6, Mid : 5 Middle element : 1 1 is found at index 5