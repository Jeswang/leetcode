//
//  anagrams.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> str;
        map<string, vector<string> > mps;
        for(string s:strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            mps[s].push_back(tmp);
        }
        for(auto mp:mps) {
            if(mp.second.size()>1)
                str.insert(str.end(), mp.second.begin(), mp.second.end());
        }
        return str;
    }
};