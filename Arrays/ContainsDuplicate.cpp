Problem Statement : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

                                                                                                               Example :

    Example 1 : Input : nums = [ 1, 2, 3, 1 ] Output : true.Explanation : 1 appeared two times in the input array.

                                                       Example 2 : Input : nums = [ 1, 2, 3, 4 ] Output : false Explanation : input array does not contain any duplicate number.Solution : Disclaimer : Don't jump directly to the solution, try it out yourself first.

                                                                                                                                                                                                        Approach 1 : we can easily find any duplicate in the array just by using two nested loops.The first loop will pick integers one by one from the array and
                                                                                                                   the second nested loop will check if there exists any duplicate or
                                                                                                               not .

                                                                                                                   Code :

    C++ Java
#include <bits/stdc++.h>
    using namespace std;

bool containsDuplicate(vector<int> nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    vector<int> nums{1, 2, 3, 1};

    bool res = containsDuplicate(nums);

    // printing the result
    if (res == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
Output: true

Time Complexity:  O(N*N), Because we are traversing the whole array again and again for every integer.

Space Complexity: O(1), Since, we are not using any extra space.

Approach 2:  If we sort the array, then all the integers will arrange in order in addition of that duplicates will also be arranged in order example: [2, 1, 3, 4, 1, 5] after sorting will be  [1, 1, 2, 3, 4, 5].

Now the problem becomes very easy. We just only need to check for adjacent or neighboring elements whether they are the same or not.

Code:

C++
Java
#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums)
{

    sort(nums.begin(), nums.end());

    for (int index = 1; index < nums.size(); index++)
    {
        if (nums[index] == nums[index - 1])
        {
            return true;
        }
    }

    return false;
}

int main()
{

    vector<int> nums{1, 2, 3, 1};

    bool res = containsDuplicate(nums);

    // printing the result
    if (res == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
Output : true

         Time Complexity : O(N *logN),
                           Sorting takes N *logN.Times where N is the length of the array

                           Space Complexity : O(1),
                           Since we are not using any extra space.If we are not counting extra space taken by sorting.

                               Approach 3 : This problem can also be solved using extra space that is by using an additional data structure that will check if the element is seen before
                               or not if seen then we can return true.

                                      For this,
                           we can use any data structure like HashSet,
                           HashTable,
                           or ArrayList as almost all data structures have a predefined function that checks if there already exists a given integer or not .

                                                                                                                                                            Code :

    C++ Java
#include <bits/stdc++.h>
    using namespace std;

bool containsDuplicate(vector<int> nums)
{

    unordered_set<int> set;

    for (int i = 0; i < nums.size(); i++)
    {
        set.insert(nums[i]);
    }

    // if it contains duplicate then the size of
    // set will not equal to the length of the array
    if (set.size() < nums.size())
        return true;

    return false;
}

int main()
{

    vector<int> nums{1, 2, 3, 1};

    bool res = containsDuplicate(nums);

    // printing the result
    if (res == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
Output : true

         Time Complexity : O(N),
                           where N is the length of the array.As searching in unorder_set takes O(1)

                               Space Complexity : O(N),
                           Where N is the number of elements stored in the set