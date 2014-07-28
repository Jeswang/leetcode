//
//  palindrome-partitioning.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",

Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/

class Solution {
public:
    vector<vector<string> > result;

    vector<vector<string> > partition(string s) {
        vector<string> cut;
        checkString(cut, s);
        return result;
    }
    
    void checkString(vector<string> lastWords, string str) {
        int len = (int)str.length();
        
        if (len == 0) {
            result.push_back(lastWords);
            return;
        }
        
        for (int i=1; i<=len; i++) {
            string frontStr = str.substr(0, i);
            if (isPalindrome(frontStr)) {
                lastWords.push_back(frontStr);
                string remainStr = str.substr(i, len-i);
                checkString(lastWords, remainStr);
                lastWords.pop_back();
            }
        }
    }
    
    bool isPalindrome(string str){
        int len = (int)str.length();
        int i, j;
        for (i=0, j=len-1; i<=j; i++, j--) {
            if (str[i] == str[j]) {
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    void run(){
//        cout<<isPalindrome("aba");
//        cout<<isPalindrome("aa");
//        cout<<isPalindrome("abac");
        vector<vector<string> > result =  partition("aab");
        for (auto it = result.begin(); it!=result.end(); it++) {
            for (auto it2 = it->begin(); it2!=it->end(); it2++) {
                cout<<*it2<<" ";
            }
            cout<<endl;
        }
    }
};