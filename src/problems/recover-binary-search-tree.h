//
//  recover-binary-search-tree.h
//
//  Created by jeswang 27/06/2014.
//

/*
 Description:
 
 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 OJ's Binary Tree Serialization:
 
 The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
 
 Here's an example:
 
 1
 / \
 2   3
 /
 4
 \
 5
 
 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    stack<TreeNode *> rStack;
    
    void recoverTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode *firstNode = NULL, *secondNode = NULL;
        TreeNode *lastNode = NULL, *currentNode = NULL;
        
        pushNode(root);
        
        while(rStack.size()!=0){
            currentNode = rStack.top();
            
            //处理栈顶元素
            
            if (lastNode != NULL) {
                if(currentNode->val < lastNode->val){
                    if (firstNode == NULL) {
                        firstNode = lastNode;
                    }
                    secondNode = currentNode;
                }
            }
            
            lastNode = currentNode;
            
            rStack.pop();
            
            if (currentNode->right != NULL)
            {
                pushNode(currentNode->right);
            }
        }
        
        int tmp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tmp;
        
    }
    
    void pushNode(TreeNode *node) {
        TreeNode *currentNode = node;
        while (currentNode != NULL)
        {
            rStack.push(currentNode);
            currentNode = currentNode->left;
        }
    }
    
    void run(){
        string s = "0 1";
        //cout<<stringFromTree(treeFromString(s));
        TreeNode *root = treeFromString(s);
        recoverTree(root);
        cout<<stringFromTree(root);
    }
};