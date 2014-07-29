//
//  generate-parentheses.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        generateParenthesis("", n, 0);
        return result;
    }
    
    void generateParenthesis(string str, int remainLeft, int allowRight){
        if (remainLeft == 0 && allowRight == 0) {
            result.push_back(str);
            return;
        }
        if (allowRight) {
            generateParenthesis(str+")", remainLeft, allowRight-1);
        }
        if (remainLeft) {
            generateParenthesis(str+"(", remainLeft-1, allowRight+1);
        }
        return;
    }
    
    void run() {
        generateParenthesis(1);
        for (auto i=result.begin(); i!=result.end(); i++) {
            cout<<*i<<endl;
        }
        
    }
};