//
//  trapping-rain-water.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

class Solution {
public:
    int trap(int A[], int n) {
        if (n<3) {
            return 0;
        }
        int low = -1;
        int acculate = 0;
        int total = 0;
        for (int i=0; i<n; i++) {
            if (low == -1) {
                low = A[i];
                continue;
            }
            
            if (A[i] >= low) {
                total += acculate;
                acculate = 0;
                low = A[i];
                
            }
            else {
                acculate += (low - A[i]);
            }
            
        }
        
        int high = low;

        low = -1;
        acculate = 0;
        
        for (int i=n-1; i>=0; i--) {

            if (low == -1) {
                low = A[i];
            }
            else if (A[i] >= low) {
                total += acculate;
                acculate = 0;
                low = A[i];
            }
            else {
                acculate += (low - A[i]);
            }
            
            if (A[i] == high) {
                break;
            }
        }
        return total;
    }
    void run() {
        int a[3] = {2, 0, 2};
        cout<<trap(a, 3);
    }
};