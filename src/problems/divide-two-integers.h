//
//  divide-two-integers.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    int divide(int sdividend, int sdivisor) {
        unsigned int dividend = sdividend;
        unsigned int divisor = sdivisor;
        
        if(divisor == 1){
            return dividend;
        }
        
        int count = 0;
        bool flag = 0;
        if(sdividend < 0) {
            flag = !flag;
            dividend = -sdividend;
        }
        
        if(sdivisor < 0) {
            flag = !flag;
            divisor = -sdivisor;
        }
        
        while(dividend >= divisor) {
            count++;
            dividend = dividend - divisor;
            
            int bigCount = 2;
            unsigned int target = divisor<<1;
            
            if (target < divisor) {
                continue;
            }
            
            while(dividend >= target) {
                count += bigCount;
                dividend = dividend - target;
                
                bigCount = bigCount << 1;
                target = target << 1;
            }
        }
        
        if(flag){
            count = -count;
        }
        
        return count;
    }
    
    void run() {
        cout<<divide(-2147483648, -2147483648);
    }
};