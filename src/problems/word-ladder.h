//
//  word-ladder.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
    unordered_map<string, int> countMap;

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        dict.insert(start);
        
        list<string> SStack;
        countMap[end] = 1;
        SStack.push_back(end);
        
        while (SStack.size() != 0) {
            string frontStr = SStack.front();
            SStack.pop_front();
            int count = countMap[frontStr];
            
            string test;
            
            for (int i=0; i<start.length(); i++) {
                test = frontStr;
                for(char c='a'; c<='z'; c++){
                    test[i] = c;
                    if (dict.find(test) != dict.end()) {
                        
                        countMap[test] = count + 1;
                        SStack.push_back(test);
                        
                        if (test == start) {
                            return count + 1;
                        }
                        
                        dict.erase(test);
                    }
                    

                }
            }

        }
        return 0;
    }
    
    
    int ladderLength2(string start, string end, unordered_set<string> &dict) {
        
        if (isLadder(start, end)) {
            return 2;
        }
        
        vector<string> nextHop;
        for (auto it = dict.begin(); it!=dict.end();) {
            if (isLadder(end, *it)) {
                nextHop.push_back(*it);
                it = dict.erase(it);
            }
            else {
                it++;
            }
        }
        
        int min = 1000;
        for (auto it = nextHop.begin(); it!=nextHop.end(); it++) {
            int count = ladderLength(start, *it, dict);
            if (count != 0 && count < min) {
                min = count;
            }
        }
        
        if (min == 1000) {
            return 0;
        }
        else {
            return min + 1;
        }
    }
    
    
    bool isLadder(string first, string second) {
        string key = first + second;

        unsigned long len = first.size();
        int diff = 0;
        for (int i=0; i<len; i++) {
            if (first[i] != second[i]) {
                diff++;
            }
            if (diff >= 2) {
                break;
            }
        }
        if (diff == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void run(){
        unordered_set<string> dict = {"hot","dot","dog","lot","log"};
        
        cout<<ladderLength("hit", "cog", dict);
    }
};