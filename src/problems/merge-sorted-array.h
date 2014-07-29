//
//  merge-sorted-array.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m==0&&n==0) {
            return;
        }
        if (m==0) {
            for (int i=0; i<n; i++) {
                A[i] = B[i];
            }
            return;
        }
        if (n==0) {
            return;
        }
        
        int i=m-1, j=n-1;
        int bCount = n;
        int totalUnset = m+n-1;
        
        while (bCount) {
            if (B[j]>=A[i]) {
                A[totalUnset] = B[j];
                totalUnset--;
                j--;
                bCount--;
            }
            else {
                while (B[j] < A[i]) {
                    A[totalUnset] = A[i];
                    totalUnset--;
                    i--;
                    if (i == -1) {
                        for (int k=0; k<=j; k++) {
                            A[k] = B[k];
                        }
                        return;
                    }
                }
            }
        }
        return;
    }
    void run() {
        int a[0];
        int b[1] = {1};
        merge(a, 0, b, 1);
    }
};