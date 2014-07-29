//
//  combinations.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())

class Solution {
public:
    vector<vector<int> > result;
    int range;
    vector<vector<int> > combine(int n, int k) {
        set<int> used;
        vector<int> status;
        range = n;
        combine(k, used, status, 0);
        return result;
    }
    
    void combine(int remain, set<int> used, vector<int> status, int start) {
        if (remain == 0) {
            result.push_back(status);
            return;
        }
        for (int i=start; i<range; i++) {
            if (!FD(used, i)) {
                used.insert(i);
                status.push_back(i+1);
                combine(remain-1, used, status, i+1);
                used.erase(i);
                status.pop_back();
            }
        }
    }
    void run() {
        combine(2, 1);
    }
};