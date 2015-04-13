// Filename: 3_sum_closest.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483637

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
    
        sort(num.begin(), num.end());

        int dist = INT_MAX;
        int res;
        
        for (int i = 0; i < n - 2; ++i) {
            int target2 = target - num[i];
            int tmp_dist;
            int tmp_res = twoSumClosest(num, i + 1, target2);
            if ((tmp_dist = abs(tmp_res - target2)) < dist) {
                dist = tmp_dist;
                res = tmp_res + num[i];
                if (res == target) {
                    return res;
                }
            }
        }

        return res;
    }
private:
    int twoSumClosest(vector<int> &num, int start, int target) {
        int begin = start;
        int end = num.size() - 1;
        int res, dist = INT_MAX;

        while (begin < end) {
            int tmp = num[begin] + num[end];
            if (tmp < target) {
                if (dist > target - tmp) {
                    dist = target - tmp;
                    res= tmp;
                }
                ++begin;
            } else if (tmp > target) {
                if (dist > tmp - target) {
                    dist = tmp - target;
                    res = tmp;
                }
                --end;
            } else {
                return tmp;
            }
        }

        return res;
    }
};

int main()
{
    int input[] = {-3,-2,-5,3,-4};
    vector<int> input_vec(input, input + sizeof(input)/sizeof(int));
    Solution solution;
    int res = solution.threeSumClosest(input_vec, -1);

    cout << res << endl;
    return 0;
}
