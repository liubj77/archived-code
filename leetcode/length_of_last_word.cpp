// Filename: length_of_last_word.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (*s == '\0') 
            return 0;
        // jump back the space characters 
        const char *end = s + strlen(s) - 1;
        while (*end == ' ')
            --end;
        if (end < s)    // all spaces 
            return 0;

        const char *last_word_start = end;
        while (last_word_start > s && *(last_word_start - 1) != ' ') {
            last_word_start --;
        }

        return end - last_word_start + 1;
    }
};

int main()
{
    Solution solution;

    cout << solution.lengthOfLastWord("a") << endl;
    cout << solution.lengthOfLastWord("a b") << endl;
    cout << solution.lengthOfLastWord("a ") << endl;
    cout << solution.lengthOfLastWord(" ") << endl;

}
