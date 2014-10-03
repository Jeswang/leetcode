//
//  longest-palindromic-substring.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        bool a[1000][1001];
        memset(a, 0, sizeof(a));
        
        size_t len = s.size();
        if(len==1||len==0) {
            return s;
        }
        
        for(int i=0; i<len; i++) {
            for(int j=0; j<=1; j++) {
                a[i][j] = true;
            }
        }
        
        int begin = 0;
        size_t size = len;
        for(int i=2; i<len+1; i++) { // size
            for(int j=0; j+i<=len; j++) { // begin
                if(s[j]==s[j+i-1]&&a[j+1][i-2]) {
                    a[j][i] = true;
                    begin = j;
                    size = i;
                }
                
            }
        }
        
        return s.substr(begin, size);
    }
    void run() {
        cout<<longestPalindrome("ccc");
    }
};