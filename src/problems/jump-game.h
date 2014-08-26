class Solution {
public:
    map<int, bool> checked;
    bool canJump(int A[], int n) {
        int canReach = 0;
        for (int i=0; i<n; i++) {
            if (i+A[i]>canReach) {
                canReach = i+A[i];
            }
            if (canReach >= n-1) {
                return true;
            }
            if (i + 1 > canReach) {
                return false;
            }
        }
        return (canReach >= n-1);
    }
    void run() {
        int A[] = {0, 1};
        cout<<canJump(A, 2);
    }
};