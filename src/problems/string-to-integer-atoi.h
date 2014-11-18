//
//  string-to-integer-atoi.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: 
It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

*/

class Solution {
public:
    void run() {
        cout<<atoi("    10522545459");
    }
    
    int multi(int i, int a) {
        int res = i;
        for (int j=1; j<a; j++) {
            res+=i;
            if ((res>>31&0x1)==1) {
                return INT_MIN;
            }
        }
        return res;
    }
    
    int atoi(const char* str)
    {
        //判断指针是否为NULL
        assert( str != NULL);
        //去除字符串前面的空格
        while(isspace(*str))
            ++str;
        //判断正负号
        int sign = 1;
        if(*str == '-')
            sign = -1;
        if(*str == '-' || *str == '+')
            ++str;
        //开始进行转换，直至第一个非数字的字符
        int result = 0;
        while(isdigit(*str))
        {
            result = multi(result, 10) + (*str-'0');
            //判断是否发生溢出
            if(((result>>31)&0x1) == 1)
            {
                if(sign > 0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            ++str;
        }
        
        //返回转换后的结果
        return result;
    }

};