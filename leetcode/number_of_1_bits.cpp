// Filename: number_of_1_bits.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Write a function that takes an unsigned integer and returns the number 
 * of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
 * so the function should return 3.
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n) {
            ++sum;
            n = n & (n-1);
        }

        return sum;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag)
                sum ++;
            flag = flag << 1;
        }
        return sum;
    }
};
