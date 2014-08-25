//
//  median-of-two-sorted-arrays.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m==0&&n==0){
            return 0;
        }
        
        if ( (m+n)%2 == 1) {
            return findNum(A, m, B, n, (m+n+1)/2); // number 1, 2, 3...
        }
        int first = findNum(A, m, B, n, (m+n)/2);
        int second = findNum(A, m, B, n, (m+n)/2+1);
        return (first + second)/2.0;
    }
    
    //Find the kth number in A and B, q is k+1
    double findNum(int A[], int m, int B[], int n, int q) {
        if(m==0) {
            return B[q-1];
        }
        if(n==0) {
            return A[q-1];
        }
        if (q == 1) {
            return min(A[0], B[0]);
        }
        if (q == m+n) {
            return max(A[m-1], B[n-1]);
        }
        
        int countA, countB;
        
        if (m<=n) {
            countA = (m+1)/2-1; // Find the center element of m
            countB = q - (m+1)/2-1; // make sure countA + 1 + countB + 1 = q + 1 (If we want 1th number, we should get 2 in total)
        }
        else {
            countB = (n+1)/2-1; // Find the center element of m
            countA = q - (n+1)/2-1; // make sure countA + 1 + countB + 1 = q + 1 (If we want 1th number, we should get 2 in total)
        }
        
        int medA = A[countA];
        int medB = B[countB];
        
        if (medA == medB) {
            return medA;
        }
        
        if(medA < medB) {
            q = q - countA - 1;
            while(countA>=0){
                A++;
                countA--;
                m--;
            }
            // Using findNum(A, m, B, n, q); will casue problem
            // Test case: {1, 4, 5} and {2, 3, 6, 7, 8}
            return findNum(A, m, B, countB+1, q);
        }
        else {
            q = q - countB - 1;
            while(countB>=0){
                B++;
                countB--;
                n--;
            }
            // Using findNum(A, m, B, n, q); will casue problem
            return findNum(A, countA+1, B, n, q);
        }
    }
    
    void run() {
        int a[] = {1,4,5};
        int b[] = {2,3,6,7,8};
        cout<<findMedianSortedArrays(a, 3, b, 5);
    }
};