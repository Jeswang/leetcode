//
//  convert-sorted-array-to-binary-search-tree.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, (int)num.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int begin, int end) {
        
        int len = end - begin + 1;
        TreeNode *result = NULL;
        if (len == 0) {
            return NULL;
        }
        if (len == 1) {
            result = new TreeNode(num[begin]);
            return result;
        }
        int centerIndex = begin + len/2;
        result = new TreeNode(num[centerIndex]);
        result->left = sortedArrayToBST(num, begin, centerIndex-1);
        result->right = sortedArrayToBST(num, centerIndex+1, end);
        
        return result;
    }
    void run() {
        vector <int> test = {1, 2, 3};
        TreeNode *tree = sortedArrayToBST(test);
        cout<<stringFromTree(tree)<<endl;
    }
};