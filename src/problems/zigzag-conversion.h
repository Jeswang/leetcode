//
//  zigzag-conversion.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 
 
 And then read line by line: "PAHNAPLSIIGYIR"
 
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string res;
        vector<string> vs(nRows, "");
        int i = 0;
        int j = 0;
        int step = 1;
        unsigned long len = s.length();
        while(j < len) {
            if(i == 0) {
                step = 1;
            }
            else if(i == nRows-1) {
                step = -1;
            }
            
            vs[i]+=s[j];
            
            j++;
            
            i += step;
        }
        
        for(int k = 0; k < nRows; k ++)
            res += vs[k];
        
        return res;
    }
    void run() {
        cout<<convert("AB", 1);
    }
};