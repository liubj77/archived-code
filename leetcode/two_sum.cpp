// Filename: two_sum.cpp
// Author: liubj77 - liubj77@gmail.com

/******************************************************************************
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
 * are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 *******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> num_index_map;

        int second_num;
        for (size_t i = 0; i < numbers.size(); ++i) {
            second_num = target - numbers[i];
            if (num_index_map.count(second_num) == 0) {
                num_index_map.insert(make_pair(numbers[i], i));
            } else {
                vector.push_back(num_index_map[second_num] + 1);
                vector.push_back(i + 1);
                break;
            }
        }
        
        return result;
    }
};
