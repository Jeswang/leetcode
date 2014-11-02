//
//  find-minimum-in-rotated-sorted-array.m
//  leetcode
//
//  Created by jeswang on 11/1/14.
//
//

class Solution {
public:
    int findMin(vector<int> &num) {
        unsigned long len = num.size();
        unsigned long _b = 0, _e = len-1, mid;
        
        while(_b!=_e) {
            mid = (_b + _e + 1)/2;
            if(mid==0||num[mid]<num[mid-1]) {
                return num[mid];
            }
            if(num[mid] > num[_e]) {
                _b = mid+1;
            }
            else {
                _e = mid-1;
            }
        }
        return num[_b];
    }
    void run() {
        vector<int> test = {6,1,2,3,4,5};
        cout<<findMin(test);
    }
};