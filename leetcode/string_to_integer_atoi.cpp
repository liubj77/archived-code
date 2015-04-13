// Filename: string_to_integer_atoi.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, 
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front.
 */

#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>

using namespace std;

class Solution {
public:
    int atoi(string str) {
        if (str.length() <= 0) {
            return 0;
        }

        int num = 0;
        bool minus = false;
        int base = 10;
        size_t start = 0, end = start + str.length() - 1;
        // trim space character
        while (str.at(start) == ' ' && start <= end) ++start;
        while (str.at(end) == ' ' &&  end >= start) --end;
        
        if (str.at(end) == 'x') {
            base = 16;
            end --;
        }

        if (str.at(start) == '-' || str.at(start) == '+') {
            minus = str.at(start) == '-' ? true : false;
            ++start;
        }

        while (start <= end) {
            if (isdigit(str.at(start))) {
                int compare_num = (numeric_limits<int>::max() - (str.at(start) - '0')) / 10;
                if (num > compare_num) {   // must overflow limits 
                    if (minus) {
                        return numeric_limits<int>::max() + 1;
                    } else {
                        return numeric_limits<int>::max();
                    }
                } 

                num = num * base + str.at(start) - '0'; 
            } else {
                break;
            }

            ++start;
        }

        if (minus) {
            num = 0 - num;
        }
    
        return num;
    }
} ;

int main()
{
    Solution solution;
    int res = solution.atoi("-2147483648");

    cout << res << endl;

    res = solution.atoi("-1");

    cout << res << endl;

    return 0;
}
