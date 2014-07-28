//
//  triangle.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]


The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

//TODO: 没有做到 O(n) 空间复杂度

class Solution {
public:
    map<string, int> counted;
    int minimumTotal(vector<vector<int> > &triangle) {
        return minimumTotal(triangle, 0, 0);
    }
    
    int minimumTotal(vector<vector<int> > &triangle, int i, int j) {
        string key = std::to_string(i) + " " + to_string(j);
        
        if (counted.find(key) != counted.end()) {
            return counted[key];
        }
        
        int len = (int)triangle.size();
        if (i+1 == len) {
            return triangle[i][j];
        }
        else {
            int result =  triangle[i][j] + fmin(minimumTotal(triangle, i+1, j), minimumTotal(triangle, i+1, j+1));
            counted[key] = result;
            return result;
        }
    }
};