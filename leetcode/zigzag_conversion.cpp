// Filename: zigzag_conversion.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }

        string result;
        string *str = new string[nRows];

        int row_index = 0;
        int orient_flag = 0; //down
        for (size_t count = 0; count < s.length(); count ++) {
            str[row_index].insert(str[row_index].end(), s.at(count));
            
            if (orient_flag == 0) {
                if (row_index + 1 >= nRows) {
                    orient_flag = 1;
                    -- row_index;
                } else {
                    ++ row_index;
                }
            } else {
                if (row_index - 1 < 0) {
                    orient_flag = 0;
                    ++ row_index;
                } else {
                    -- row_index;
                }
            }
        }

        for (int i = 0; i < nRows; ++i) {
            result.append(str[i]);
        }

        delete [] str;

        return result;
    }
};

