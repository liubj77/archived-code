// Filename: 3_sum.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        
        if (num.size() < 3) {
            return result;
        }

        sort(num.begin(), num.end());

        int duplicate = num[0];
        for (size_t i = 0; i < num.size() - 2; ++i) {
            if (i != 0 && num[i] == duplicate) {
                continue;
            }

            duplicate = num[i];
            
            int begin = i + 1;
            int end = num.size() - 1;
            while (begin < end) {
                if (duplicate + num[begin] + num[end] == 0) {
                    vector<int> temp_vec;
                    temp_vec.push_back(duplicate);
                    temp_vec.push_back(num[begin]);
                    temp_vec.push_back(num[end]);
                    result.push_back(temp_vec);
                    // here should skip equal number
                    while (begin < end && num[begin + 1] == num[begin]) ++begin;
                    while (end > begin && num[end - 1] == num[end]) --end;
                    ++begin;
                    --end;
                } else if (duplicate + num[begin] + num[end] < 0) {
                    while (begin < end && num[begin + 1] == num[begin]) ++begin;
                    ++begin;
                } else {
                    while (end > begin && num[end - 1] == num[end]) --end;
                    --end;
                }
            }
        }

        return result;
    }
};

int main()
{
    int input[] = {-1, 0, 1, 2, -1, -4};
    vector<int> input_vec(input, input + sizeof(input)/sizeof(int));

    Solution solution;
    vector<vector<int> > res = solution.threeSum(input_vec);

    for (vector<vector<int> >::iterator iter = res.begin();
            iter != res.end(); ++iter) {
        for (vector<int>::iterator iter1 = iter->begin();
                iter1 != iter->end(); ++iter1) {
            cout << *iter1 << " ";
        }
        cout << endl;
    }

    return 0;
}
