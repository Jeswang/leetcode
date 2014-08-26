//
//  search-for-a-range.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 Given a sorted array of integers, find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */

class Solution {
public:
    void run() {
        int A[] = {0,0,2,3,4,4,4,5};
        vector<int> res = searchRange(A, 8, 5);
        for(auto it = res.begin(); it!=res.end(); it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start = 1;
        int end = n;
        int selected = (start + end) / 2;
        bool find = false;
        do {
            if(A[selected-1] < target) {
                if (start == selected) {
                    start ++;
                }
                else {
                    start = selected;
                }
            }
            else if(A[selected-1] > target) {
                end = selected;
            }
            else if(A[selected-1] == target) {
                find = true;
                break;
            }
            selected = (start + end) / 2;
        } while(start!=end);
        
        if (!find) {
            if (A[start-1]==target) {
                find = true;
                selected = start;
            }
        }
            
        vector<int> res;
        
        if(find) {
            start = selected-1;
            end = selected-1;
            int tmp = selected;
            while(tmp > 1) {
                tmp--;
                if(A[tmp-1] == target){
                    start--;
                }
                else {
                    break;
                }
            }
            
            tmp = selected;
            while(tmp < n+1) {
                tmp++;
                if(A[tmp-1] == target){
                    end++;
                }
                else {
                    break;
                }
            }
            res.push_back(start);
            res.push_back(end);
        }
        if (res.size() == 0){
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
    
};