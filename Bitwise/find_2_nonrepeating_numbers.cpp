https://leetcode.com/problems/single-number-iii



//brute force     //n*logm + m
// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         for(auto x : nums) freq[x]++;      //n*logm

//         vector<int> v;
//         for(auto x : freq){              //m
//             if(x.second == 1) v.push_back(x.first);
//         }
//         return v;

//     }
// };

1. Compute the XOR of all numbers → this gives xorAll = a ^ b where a and b are the two unique numbers.
2. Find the rightmost set bit in xorAll. This bit differs between a and b.
    We can extract it using mask = xorAll & -xorAll.
3. Partition numbers into two groups:
    Group 1: numbers with this bit set.
    Group 2: numbers with this bit not set.
4. XOR within each group → duplicates cancel out, leaving a in one group and b in the other.
5. Return {a, b}.


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorAll = 0;

        // Step 1: XOR all numbers → result = xor of the two unique numbers
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find the rightmost set bit (distinguishing bit between the two unique numbers)
        long rightmostBit = xorAll & -xorAll;
        // (This isolates the lowest bit where the two numbers differ)

        int num1 = 0, num2 = 0;

        // Step 3: Partition numbers into two groups and XOR separately
        for (int num : nums) {
            if (num & rightmostBit) {
                num1 ^= num;  // Group 1
            } else {
                num2 ^= num;  // Group 2
            }
        }

        // Step 4: Return the two unique numbers
        return {num1, num2};
    }
};