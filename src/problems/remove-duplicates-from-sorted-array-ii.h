//
//  remove-duplicates-from-sorted-array-ii.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

#define foreach(container,it) for(auto it = (container).begin();it!=(container).end();++it)
#define FD(X, Y) (X.find(Y)!=X.end())
#define SIZE(A) ((int)A.size())

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        int last = -1;
        int lastFlag = false;
        int total = n;
        for (int i=0; i<total; i++) {
            
            if (lastFlag == false) {
                count += 1;
                lastFlag = true;
                last = A[i];
            }
            else {
                if (last == A[i]) {
                    count += 1;
                }
                else {
                    count = 1;
                }
                
                last = A[i];

                if (count > 2) {
                    //move remain farward
                    total -= 1;
                    i--;
                    for (int j=i+1; j<total+1; j++) {
                        A[j-1] = A[j];
                    }
                }
            }
        }
        return total;
    }
};