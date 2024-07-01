#include <iostream>

/***************************************** Solution *****************************************/

class Solution
{
public:
    // Function to calculate the number of set bits (Hamming weight) in an integer n
    int hammingWeight(int n)
    {
        int count = 0; // Initialize count to store the number of set bits

        // Iterate until all bits of n are processed (n becomes zero)
        while (n != 0)
        {
            count += n & 1; // Check if the least significant bit of n is set (1)
            n >>= 1;        // Right shift n by 1 bit to check the next bit
        }

        return count; // Return the total count of set bits in n
    }
};

/***************************************** Main Function *****************************************/

int main()
{
    int n = 11; // Example input

    Solution sol;                      // Create an instance of the Solution class
    int result = sol.hammingWeight(n); // Calculate the number of set bits in n

    // Output the result
    std::cout << "Number of set bits in " << n << " (binary representation): " << result << std::endl;

    return 0; // Exit the program
}
