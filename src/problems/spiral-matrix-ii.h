//
//  spiral-matrix-ii.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())

class Solution {
public:
    vector<vector<int> > result;
    
    vector<vector<int> > generateMatrix(int n) {
        if (n==0) {
            return result;
        }
        
        while (SIZE(result)!=n) {
            vector<int> line(n);
            result.push_back(line);
        }
        
        int count = n-1;
        int right = count, down = count, left = count, up = count;
        int x = 0, y = 0;
        for (int i=1; i<n*n+1; i++) {
            result[y][x] = i;


            if (right > 0) {
                right--;
                x += 1;
            }
            else if (down > 0) {
                down--;
                y += 1;
            }
            else if (left > 0) {
                left--;
                x -= 1;
            }
            else if (up > 0) {
                up--;
                y -= 1;
                if (up == 0) {
                    count -= 2;
                    right = count, down = count, left = count, up = count;
                    x += 1;
                    y += 1;
                }
            }
        }
        return result;
    }
    
    void run() {
        generateMatrix(4);
        foreach(result, it){
            foreach(*it, it2){
                cout<<*it2<<" ";
            }
        }
        
    }
};