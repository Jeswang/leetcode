//
//  minimum-path-sum.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FD(X, Y) X.find(Y)!=X.end()

#define foreach(container,it) for(typeof((container).begin()) it = (container).begin();it!=(container).end();++it)

class Solution {
public:
    int m, n;
    map<string, int> counted;
    
    int minPathSum(vector<vector<int> > &grid) {
        n = SIZE(grid);
        if (n == 0) {
            return 0;
        }
        m = SIZE(grid[0]);
        return minPathSum(grid, 0, 0);
    }
    
    int minPathSum(vector<vector<int> > &grid, int beginX, int beginY) {
        string key = to_string(beginX) + "_" + to_string(beginY);
        
        if (FD(counted, key)) {
            return counted[key];
        }
        
        int moveRight = 99999, moveDown = 99999;
        if (beginX == m-1 && beginY == n-1) {
            return grid[beginY][beginX];
        }
        
        if (beginX<m-1) {
            moveRight = minPathSum(grid, beginX+1, beginY);
        }
        if (beginY<n-1) {
            moveDown = minPathSum(grid, beginX, beginY+1);
        }
        int min = fmin(moveRight, moveDown);
        
        counted[key] = grid[beginY][beginX] + min;
        
        return grid[beginY][beginX] + min;
    }
    
    void run() {
        vector<vector<int> > test;
        vector<int> i = {1,2,5};
        vector<int> j = {3,2,1};
        test.push_back(i);
        test.PB(j);
        cout<<minPathSum(test);
    }
};