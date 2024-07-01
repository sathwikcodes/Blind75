class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b; // Calculate the carry using bitwise AND
            a = a ^ b;         // Calculate the sum without considering carry using bitwise XOR
            b = carry << 1;    // Shift the carry to the left to prepare for the next addition iteration
        }
        return a; // Return the final sum
    }
};
