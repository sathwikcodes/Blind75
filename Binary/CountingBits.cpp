// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
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

// Example: Counting Bits for i = 13
// Let's use i = 13 (binary 1101) as an example to illustrate how this works:

// Initialization:

// num = 13 (binary 1101)
// sum = 0
// First Iteration:

// num % 2 = 13 % 2 = 1 (the least significant bit is 1)
// sum = sum + 1 = 0 + 1 = 1
// num = num / 2 = 13 / 2 = 6 (binary 0110)
// Second Iteration:

// num % 2 = 6 % 2 = 0 (the least significant bit is 0)
// sum = sum + 0 = 1 + 0 = 1
// num = num / 2 = 6 / 2 = 3 (binary 0011)
// Third Iteration:

// num % 2 = 3 % 2 = 1 (the least significant bit is 1)
// sum = sum + 1 = 1 + 1 = 2
// num = num / 2 = 3 / 2 = 1 (binary 0001)
// Fourth Iteration:

// num % 2 = 1 % 2 = 1 (the least significant bit is 1)
// sum = sum + 1 = 2 + 1 = 3
// num = num / 2 = 1 / 2 = 0 (binary 0000)
// At this point, the while loop exits because num is now 0.

// Summary
// First Iteration: num = 13 (1101), sum = 1
// Second Iteration: num = 6 (0110), sum = 1
// Third Iteration: num = 3 (0011), sum = 2
// Fourth Iteration: num = 1 (0001), sum = 3
// The final value of sum is 3, which correctly represents the number of 1 bits in the binary representation of 13 (i.e., 1101).

class Solution
{
public:
    vector<int> countBits(int n)
    {

        // n+1 as we are going to count from 0 to n
        vector<int> t(n + 1);

        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;

        // we can compute current set bit count using previous count
        // as x/2 in O(1) time

        // i%2 will be 0 for even number ans 1 for odd number

        for (int i = 1; i <= n; ++i)
            t[i] = t[i / 2] + i % 2;

        return t;
    }
};

// for o(N)