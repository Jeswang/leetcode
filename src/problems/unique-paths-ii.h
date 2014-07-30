//
//  unique-paths-ii.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())
#define PB(X) push_back(X)

class Solution {
public:
    vector<vector<int> > obstacleGrid_;
    map<string, int> checked;
    int total;
    int m,n;
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        obstacleGrid_ = obstacleGrid;
        total = 0;
        n = SIZE(obstacleGrid);
        if (n == 0) {
            return 0;
        }
        else {
        }
        m = SIZE(obstacleGrid[0]);
        
        if (m>0 && n>0 && obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        total = goFrom(0, 0);
        return total;
    }
    
    int goFrom(int x, int y) {
        string key = to_string(x)+"_"+to_string(y);
        
        if (FD(checked, key)) {
            return checked[key];
        }
        
        int count = 0;
        if (x == m-1 && y == n-1) {
            return 1;
        }
        else {
            if (x <= m-2 && obstacleGrid_[y][x+1]!=1) {
                count += goFrom(x+1, y);
            }
            if (y <= n-2 && obstacleGrid_[y+1][x]!=1) {
                count += goFrom(x, y+1);
            }
        }
        
        checked[key] = count;
        return count;
    }
};