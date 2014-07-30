//
//  length-of-last-word.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())
#define PB(X) push_back(X)

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str = s;
        int n = SIZE(str);
        int count = 0;
        int lastCount = 0;
        bool spaceFlag = false;
        for (int i=0; i<n; i++) {
            if (str[i] == ' ') {
                if (spaceFlag == false) {
                    lastCount = count;
                    spaceFlag = true;
                }
                count = 0;
            }
            else {
                count++;
                spaceFlag = false;
            }
        }
        return count==0?lastCount:count;
    }
};