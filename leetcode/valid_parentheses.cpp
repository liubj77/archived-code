// Filename: valid_parentheses.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid 
 * but "(]" and "([)]" are not.
 *
 */

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ch_vec;

        for (size_t i = 0; i < s.length(); ++i) {
            if (ch_vec.size()) {
                if (ch_vec.top() == '(' && s.at(i) == ')') {
                    ch_vec.pop();
                } else if (ch_vec.top() == '{' && s.at(i) == '}') {
                    ch_vec.pop();
                } else if (ch_vec.top() == '[' && s.at(i) == ']') {
                    ch_vec.pop();
                } else {
                    ch_vec.push(s.at(i));
                }
            } else {
                ch_vec.push(s.at(i));
            }
        }

        if (ch_vec.size()) {
            return false;
        }

        return true;
    }
};
