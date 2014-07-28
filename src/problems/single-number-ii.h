//
//  single-number-ii.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for(int i = 0; i < n; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            xthrees = ~(ones & twos);
            ones &= xthrees;
            twos &= xthrees;
        }
        
        return ones;
    }
    
    void run() {
        int a[5] = {1, 2, 1, 1};
        cout<<singleNumber(a, 4);
    }
};