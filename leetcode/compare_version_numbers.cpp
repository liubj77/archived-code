// Filename: compare_version_numbers.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> str_vec1, str_vec2;
        stringSplit(version1, ".", str_vec1);
        stringSplit(version2, ".", str_vec2);

        // pop the last zero
        while (str_vec1.size() > 0 && atoi(str_vec1.back().c_str()) == 0) {
            str_vec1.pop_back();
        }   
        while (str_vec2.size() > 0 && atoi(str_vec2.back().c_str()) == 0) {
            str_vec2.pop_back(); 
        }

        for (size_t i = 0; i < str_vec1.size() && i < str_vec2.size(); ++i) {
                if (atoi(str_vec1[i].c_str()) < atoi(str_vec2[i].c_str())) {
                return -1;
            } else if (atoi(str_vec1[i].c_str()) > atoi(str_vec2[i].c_str())) {
                return 1;
            }
        }

        if (str_vec1.size() > str_vec2.size()) {
            return 1;
        } else if (str_vec1.size() < str_vec2.size()) {
            return -1;
        }

        return 0;
    }
private:
    void stringSplit(string str, string delim, vector<string> &str_vec) {
        size_t start = 0;
        size_t end = str.find(delim);
        while (end != string::npos) {
            str_vec.push_back(str.substr(start, end - start));
            start = end + delim.length();
            end = str.find(delim, start);
        }
        if (start < str.size()) {
            str_vec.push_back(str.substr(start, end - start));
        }
    }
};

int main() 
{
    Solution solution;
    int ret = solution.compareVersion("1", "0");
    
    cout << ret << endl;

    return 0;
}
