//
//  construct-binary-tree-from-inorder-and-postorder-traversal.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return this->buildTreeEx(postorder.begin()-1, postorder.end()-1, inorder.begin(), inorder.end());
    }
    
    TreeNode *buildTreeEx(vector<int>::iterator postB, vector<int>::iterator postE, vector<int>::iterator inB, vector<int>::iterator inE) {
        if(postB==postE)
            return NULL;
        
        TreeNode *root = new TreeNode(*postE);
        int currentVal = *postE;
        postE--;
        
        if(postB==postE)
            return root;
        
        int tmpLen = 0;
        for(auto it=inB; it!=inE; it++) {
            if(*it==currentVal) {
                root->left = buildTreeEx(postB, postB+tmpLen, inB, it);
                root->right = buildTreeEx(postB+tmpLen, postE, it+1, inE);
                break;
            }
            tmpLen++;
        }
        return root;
        
    }
    
};