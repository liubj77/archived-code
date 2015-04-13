// Filename: rotate_array.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (k <= 0) {
            return;
        }
        if (n <= k) {
            k = k % n;
        }

        int left = n - k;
        
        rotate(nums, left);
        rotate(nums + left, k);

        rotate(nums, n);
    }
private:
    void rotate(int nums[], int n) {
        int begin = 0; 
        int end = begin + n - 1;
        while (begin < end) {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            ++begin;
            --end;
        }
    }
};
    
