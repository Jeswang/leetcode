//
//  plus-one.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = (int)digit.size();
        int flag = false;
        for (int i=len-1; i>=0; i--) {
            digits[i] = digits[i] + 1;
            if (digits[i] == 10) {
                flag = true;
                digits[i] = 0;
                continue;
            }
            else {
                return digits;
            }
        }
        if (flag) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};