// Filename: pascals_triangle.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for (int i = 1; i <= numRows; ++i) {
            result.push_back(generate_row(i));
        }

        return result;
    }

private:
    vector<int> generate_row(int numRows) {
        if (numRows == 1) {
            vector<int> res;
            res.push_back(1);
            return res;
        }

        if (numRows == 2) {
            vector<int> res;
            res.push_back(1);
            res.push_back(1);
            return res;
        }
        
        vector<int> former_vec = generate_row(numRows - 1);
        
        vector<int> res;
        res.push_back(1);
        for (size_t i = 0; i < former_vec.size() - 1; ++i) {
            res.push_back(former_vec[i] + former_vec[i+1]);
        }
        res.push_back(1);

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > result = solution.generate(5);

    for (int i = 0; i < 5; ++i) {
        for (int j =0; j < result[i].size(); ++j) {
            cout<< result[i][j] << " ";
        }

        cout << endl;
    }
}

