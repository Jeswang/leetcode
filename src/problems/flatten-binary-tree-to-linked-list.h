//
//  flatten-binary-tree-to-linked-list.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6


The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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

//TODO: runtime error?

class Solution {
public:
    void flatten(TreeNode *root) {
        flattenWithReturn(root);
    }
    /**
     *  faltten a tree
     *
     *  @param root root
     *
     *  @return the last node
     */
    TreeNode *flattenWithReturn(TreeNode *root) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode *leftLastNode = NULL, *rightLastNode = NULL, *left, *right;
        
        left = root->left;
        right = root->right;
        
        if (left != NULL) {
            leftLastNode = flattenWithReturn(left);
            root->right = left;
            root->left = NULL;
        }
        else {
            leftLastNode = root;
        }
        
        if (right != NULL) {
            rightLastNode = flattenWithReturn(right);
            leftLastNode->right = right;
            return rightLastNode;
        }
        else {
            return leftLastNode;
        }
        
    }
    
    void run(){
        string treeString = "1 2 3 5 # 4";
        TreeNode *tree = treeFromString(treeString);
        flatten(tree);
        cout<<stringFromTree(tree);
    }
};