//
//  construct-binary-tree-from-preorder-and-inorder-traversal.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return this->buildTreeEx(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode *buildTreeEx(vector<int>::iterator preB, vector<int>::iterator preE, vector<int>::iterator inB, vector<int>::iterator inE) {
        if(preB==preE)
            return NULL;
        
        TreeNode *root = new TreeNode(*preB);
        int currentVal = *preB;
        preB++;
        
        if(preB==preE)
            return root;
        
        int tmpLen = 0;
        for(auto it=inB; it!=inE; it++) {
            if(*it==currentVal) {
                root->left = buildTreeEx(preB, preB+tmpLen, inB, it);
                root->right = buildTreeEx(preB+tmpLen, preE, it+1, inE);
                break;
            }
            tmpLen++;
        }
        return root;
        
    }
    
    void run() {
        vector<int> a = {1, 2, 3};
        vector<int> b = {1, 2, 3};
        cout<<stringFromTree(buildTree(a, b));
    }
};