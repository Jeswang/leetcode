//
//  letter-combinations-of-a-phone-number.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/


class Solution {
public:
    string dic[9] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        int len = (int)digits.size();
        
        vector<string> res;
        if(len==0){
            res.push_back("");
            return res;
        }
        
        int i = digits[0] - '1';
        string s = dic[i];
        string subS = digits.substr(1, digits.size()-1);
        vector<string> more = letterCombinations(subS);
        for(int i=0; i<s.size(); i++){
            for(auto it=more.begin(); it!=more.end(); it++){
                res.push_back(s[i]+*it);
            }
        }
        return res;
    }
    
    void run(){
        string test = "23";
        vector<string> res = letterCombinations(test);
        for (auto i=res.begin(); i!=res.end(); i++) {
            printf("%s ", (*i).c_str());
        }
    }
};