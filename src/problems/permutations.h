//
//  permutations.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
#define foreach(container,it) for(typeof((container).begin()) it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) X.find(Y)!=X.end()
#define SIZE(A) ((int)A.size())

class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
        set<int> selected;
        vector<int> currentStatuts;
        permute(num, selected, currentStatuts);
        return result;
    }
    
    void permute(vector<int> &num, set<int> selected, vector<int> currentStatuts){
        
        if (SIZE(selected) == SIZE(num)) {
            result.push_back(currentStatuts);
            return;
        }
        
        foreach(num, it) {
            if (!FD(selected, *it)) {
                selected.inset(*it);
                currentStatuts.push_back(*it);
                permut(num, selected, currentStatuts);
                selected.erase(*it);
                currentStatuts.pop_back();
            }
        }
    }
};