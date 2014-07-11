//
//  valid-parentheses.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        string left[3] = {"(", "{", "["};

        map<string, string> validPair;
        validPair["("] = ")";
        validPair["{"] = "}";
        validPair["["] = "]";
        
        vector<string> bStack;
        for (int i=0; i<s.size(); i++) {
            string b = s.substr(i, 1);
            if (b == left[0] || b == left[1] || b == left[2]) {
                bStack.push_back(b);
            }
            else{
                if (bStack.size() == 0) {
                    return false;
                }
                
                string bTop = bStack.back();
                bStack.pop_back();
                if (validPair[bTop]==b) {
                    continue;
                }
                return false;
            }
        }
        if (bStack.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void run(){
        cout<<isValid("()[]");
    }
};