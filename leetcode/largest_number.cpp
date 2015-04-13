// Filename: largest_number.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

class Solution {
public:
    static bool mycomp(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int> &num) {
        vector<string> str_num;
        for (size_t i = 0; i < num.size(); ++i) {
            str_num.push_back(to_string(num[i]));
        }

        sort(str_num.begin(), str_num.end(), mycomp);

        string result;
        bool skip_zero = false;
        for (size_t i = 0; i < str_num.size(); ++i) {
            if (skip_zero == false) {
                if (atoi(str_num[i].c_str()) != 0) {
                    skip_zero = true;
                    result.append(str_num[i]);
                }
            } else {
                result.append(str_num[i]);
            }
        }

        if (result.size() == 0) {
            result.append("0");
        }

        return result;
    }
};
