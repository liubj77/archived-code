// Filename: factorial_trialing_zeros.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

/* count how many 5s in n's factors
 * result = floor(n/5) + floor(n/25) + floor(n/125) + ... 
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int base = 5;
        int temp;

        /* should consider the int overflow if use base *= 5 */
        while ((temp = n / base) > 0) {
            count += temp;
            n = temp;
        }

        return count;
    }
};
