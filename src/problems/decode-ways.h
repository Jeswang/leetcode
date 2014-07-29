//
//  decode-ways.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12",
it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:
    map<string, int> replaceMap = {
        {"1", 'a'},
        {"2", 'b'},
        {"3", 'c'},
        {"4", 'd'},
        {"5", 'e'},
        {"6", 'f'},
        {"7", 'g'},
        {"8", 'h'},
        {"9", 'i'},
        {"10", 'j'},
        {"11", 'k'},
        {"12", 'l'},
        {"13", 'm'},
        {"14", 'n'},
        {"15", 'o'},
        {"16", 'p'},
        {"17", 'q'},
        {"18", 'r'},
        {"19", 's'},
        {"20", 't'},
        {"21", 'u'},
        {"22", 'v'},
        {"23", 'w'},
        {"24", 'x'},
        {"25", 'y'},
        {"26", 'z'},
    };
    
    map<string, int> alreadyCount;
    
    int numDecodings(string s) {
        int len = (int)s.length();
        if (len == 0) {
            return 0;
        }
        else {
            return realNumDecodings(s);
        }
    }
    
    int realNumDecodings(string s) {
        
        int count = 0;
        int len = (int)s.length();
        
        if (len == 0) {
            return 1;
        }
        
        if (alreadyCount.find(s) != alreadyCount.end()) {
            return alreadyCount[s];
        }
        
        if(len>=1){
            string one = s.substr(0, 1);
            if (replaceMap.find(one) != replaceMap.end()) {
                count += realNumDecodings(s.substr(1, len-1));
            }
        }
        
        if (len >= 2) {
            string two = s.substr(0, 2);
            if (replaceMap.find(two) != replaceMap.end()) {
                count += realNumDecodings(s.substr(2, len-2));
            }
        }
        
        alreadyCount[s] = count;
        return count;
    }
    
    void run() {
        cout<<numDecodings("226");
    }
};