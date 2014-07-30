//
//  rotate-image.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?
 */

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())
#define PB(X) push_back(X)

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = SIZE(matrix);
        if (n == 0) {
            return;
        }
        
        int baseX = 0;
        int baseY = 0;
        int range = n-1;
        
        while (range > 0) {
            for (int i=0; i<range; i++) {
                int temp = matrix[baseY+range-i][baseX];
                matrix[baseY+range-i][baseX] = matrix[baseY+range][baseX+range-i];
                matrix[baseY+range][baseX+range-i] = matrix[baseY+i][baseX+range];
                matrix[baseY+i][baseX+range] = matrix[baseY][baseX+i];
                matrix[baseY][baseX+i] = temp;
            }
            range -= 2;
            baseX ++;
            baseY ++;
        }
    }
    void run() {
        vector<vector<int> > test;
        vector<int> i = {1,2,3,4};
        vector<int> i2 = {5,6,7,8};
        vector<int> i3 = {9,10,11,12};
        vector<int> i4 = {13,14,15,16};
        
        test.PB(i);
        test.PB(i2);
        test.PB(i3);
        test.PB(i4);
        
        rotate(test);
    }
};