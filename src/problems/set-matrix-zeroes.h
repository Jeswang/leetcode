//
//  set-matrix-zeroes.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())

// Learn from: https://oj.leetcode.com/discuss/1650/is-there-a-better-constant-space-solution

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row = false, col = false;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row = true;
                    if (j == 0) col = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        
        if(row)  for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if(col)  for (int i = 0; i < m; ++i) matrix[i][0] = 0;    
    }
};