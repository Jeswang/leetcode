//
//  combination-sum.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 
 
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 
 */


class Solution {
public:
    void run() {
        vector<int> test;
        test.push_back(1);
        combinationSum(test, 2);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return realCombinationSum(candidates, target, candidates.begin());
    }
    
    vector<vector<int> > realCombinationSum(vector<int> &candidates, int target, vector<int>::iterator begin) {
        vector<vector<int> > res;
        
        if(target < 0) {
            return res;
        }
        
        if(target == 0){
            vector<int> empty;
            res.push_back(empty);
            return res;
        }
        
        for (auto it = begin; it!=candidates.end(); it++) {
            int current = *it;
            vector<vector<int> > tmp = realCombinationSum(candidates, target - current, it);
            foreach(tmp, it2){
                it2->insert(it2->begin(), current);
            }
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};