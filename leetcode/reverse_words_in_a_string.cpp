// Filename: reverse_words_in_a_string.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // trim all space at begin and end
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        // trim continuous space
        trimContinousSpace(s);

        int len = s.length();
        int start = 0;
        int end = start;

        while (end < len) {
            if (s.at(end) == ' ') {
                reverseWords(s, start, end - 1);
                ++ end;
                start = end;
            } else {
                ++end;
            }
        }

        if (start < end) {
            reverseWords(s, start, end - 1);
        }
        
        // reverse all words
        reverseWords(s, 0, len - 1);
    };

private:
    void trimContinousSpace(string &s) {
        int len = s.length();
        bool keepspace = false; // if keep space,  
        int new_char_index = 0;
        for (int i = 0; i < len; ++i) {
            if (s.at(i) != ' ') {
                s[new_char_index] = s[i];
                keepspace = true;
                ++new_char_index;
            } else {
                if (keepspace) {
                    s[new_char_index] = s[i];
                    keepspace = false;  
                    ++new_char_index;
                }
            }
        }

        // assign s
        if (keepspace == false && new_char_index > 0) {
            s = s.substr(0, new_char_index - 1);
        } else {
            s = s.substr(0, new_char_index);
        }
    }
    void reverseWords(string &s, int begin, int end) {
        while (begin < end) {
            char c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            ++begin;
            --end;
        } 
    }
};

int main()
{
    Solution solution;
    string str = "the   sky is blue";
    solution.reverseWords(str);

    cout << str << endl;
    
    return 0;
}
