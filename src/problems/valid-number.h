//
//  valid-number.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Validate if a given string is numeric.

Some examples:
"0" => true
"   0.1  " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber(const char *s) {
        string str = s;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(str.length() == 0){
            return false;
        }
        
        char tmp[100];
        strcpy (tmp, s);
        char* c = tmp;
        std::strtod(c, &c);
        
        str = c;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        
        if(str.length() == 0){
            return true;
        }
        else {
            return false;
        }
    }
    void run(){
        cout<<isNumber("1 ");
        
    }
};