// Filename: majority_element.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given an array of size n, find the majority element. The majority element 
 * is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

class Solution {
    public:
    int majorityElement(vector<int> &num) {
        int major = num[0], count = 1;
        for (size_t i = 1; i < num.size(); ++i) {
            if (count == 0) {
                major = num[i];
                count ++;
                continue;
            }
                    
            if (num[i] != major) {
                count --;
            } else {
                count ++;
            }
        }
        
        return major;
    }
};
