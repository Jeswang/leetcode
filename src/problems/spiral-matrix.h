//
//  spiral-matrix.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 
 You should return [1,2,3,6,9,8,7,4,5].
 */

class Solution {
public:
    void run() {
        vector<vector<int> > input = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };
        vector<int> res = spiralOrder(input);
        for (auto i : res) {
            cout<<i;
        }
        
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        
        int direction = 0;
        int a[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
        
        unsigned long h = matrix.size() - 1;
        unsigned long w = matrix[0].size();
        unsigned long _w = w, _cw = 0;
        unsigned long _h = h, _ch = 0;
        for(int i=0; i<matrix.size()*matrix[0].size(); i++) {
            res.push_back(matrix[_ch][_cw]);
            if(direction%2==0) {
                _w -= 1;
                if(_w == 0) {
                    w -= 1;
                    _w = w;
                    direction = (direction + 1) % 4;
                }
            }
            else if(direction%2==1) {
                _h -= 1;
                if(_h == 0) {
                    h -= 1;
                    _h = h;
                    direction = (direction + 1) % 4;
                }
            }
            _cw += a[direction][0];
            _ch += a[direction][1];
        }
        return res;
    }
};