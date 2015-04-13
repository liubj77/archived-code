// Filename: reverse_integer.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */

class Solution {
public:
    int reverse(int x) {
        bool negative_flag = false;
        if (x < 0) {
            negative_flag = true;
        }
        
        int n = abs(x);
        int num;

        vector<int> integer_vec;
        while (n) {
            num = n % 10;
            integer_vec.push_back(num);
            n = (n - num) / 10;
        }
        
        int result = 0;
        for (size_t i = 0; i < integer_vec.size(); ++i) {
            if (result > (numeric_limits<int>::max() - integer_vec[i]) / 10) {
                return 0;
            } else {
                result = result * 10 + integer_vec[i];
            }
        }
        
        if (negative_flag) {
            result = 0 - result;
        }
        
        return result;
    }
};
