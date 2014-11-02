//
//  4sum.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.


    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    void run() {
        vector<int> input = {0,0,0};
        vector<vector<int> > res = fourSum(input, 0);
        for(auto i:res) {
            for(auto j:i) {
                cout<<j;
            }
            cout<<endl;
        }
    }
    map<int, vector<pair<int, int> > > m;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unsigned long len = num.size();
        
        vector<vector<int> > res;

        if (len==0) {
            return res;
        }
        for(int i=0; i<len-1; i++) {
            for(int j=i+1; j<len; j++) {
                int k = num[i] + num[j];
                if(m.find(k)==m.end()) {
                    vector<pair<int, int> > tmp;
                    tmp.push_back(make_pair(i, j));
                    m[k] = tmp;
                }
                else {
                    m[k].push_back(make_pair(i, j));
                }
            }
        }
        
        for(auto i=m.begin(); i!=m.end(); ) {
            if(m.find(target-(*i).first)!=m.end()) {
                //找到了，两两匹配
                vector<pair<int, int> > first, second;
                first = (*i).second;
                second = m[target-(*i).first];
                for(auto j:first)
                    for(auto k:second) {
                        vector<int> tmp;
                        if(j.first==k.second || j.first==k.first || j.second == k.first || j.second == k.second) {
                            continue;
                        }
                        else {
                            tmp.push_back(num[j.first]);
                            tmp.push_back(num[j.second]);
                            tmp.push_back(num[k.first]);
                            tmp.push_back(num[k.second]);
                            sort(tmp.begin(), tmp.end());
                            res.push_back(tmp);
                        }
                    }
                i++;
            }
            else {
                i = m.erase(i);
            }
        }
        return res;
    }
    
};