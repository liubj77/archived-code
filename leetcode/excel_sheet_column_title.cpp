// Filename: excel_sheet_column_title.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB 
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int res = 0;

        while (n) {
            res = (n -1) % 26;  // 1->A, if 0->A, no need -1
            result.insert(result.begin(), 'A' + res);
            n -=  res;
            n /= 26;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.convertToTitle(53) << endl;

    return 0;
}
