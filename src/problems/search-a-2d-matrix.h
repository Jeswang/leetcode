//
//  search-a-2d-matrix.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = (int)matrix.size();
        if (n == 0) {
            return false;
        }
        int m = (int)matrix[0].size();
        
        for (int i=0; i<n; i++) {
            if (matrix[i][m-1] > target) {
                for (int j=0; j<m; j++) {
                    if (matrix[i][j]>target) {
                        return false;
                    }
                    else if(matrix[i][j] == target){
                        return true;
                    }
                }
            }
            else if (matrix[i][m-1] == target) {
                return true;
            }
        }
        return false;
    }
};