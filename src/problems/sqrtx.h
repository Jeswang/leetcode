//
//  sqrtx.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Implement int sqrt(int x).
Compute and return the square root of x.
*/

class Solution {
public:
    
    int sqrt(int x) {
        long long ans = 0l;
        long long bit = 1l << 16;
        while(bit > 0) {
            ans |= bit;
            if (ans * ans > x) {
                ans ^= bit;
            }
            bit >>= 1;
        }
        return (int)ans;
    }
    
};