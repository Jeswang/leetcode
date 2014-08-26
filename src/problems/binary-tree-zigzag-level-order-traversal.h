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
    void run() {
        string s = "1 2 3";
        zigzagLevelOrder(treeFromString(s));
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL) {
            return res;
        }
        
        bool isLeft = true;
        
        vector<TreeNode*> tmp;
        tmp.push_back(root);
        
        while(tmp.size()!=0) {
            res.push_back(getInts(tmp, isLeft));
            tmp = nextLevel(tmp);
            isLeft = !isLeft;
        }
        return res;
    }
    
    vector<int> getInts(vector<TreeNode*> level, bool isLeft) {
        vector<int> res;
        foreach(level, it) {
            if(isLeft)
                res.push_back((*it)->val);
            else
                res.insert(res.begin(), (*it)->val);
        }
        return res;
    }
    
    vector<TreeNode*> nextLevel(vector<TreeNode*> lastLevel) {
        vector<TreeNode*> res;
        foreach(lastLevel, it) {
            if((*it)->left!=NULL) {
                res.push_back((*it)->left);
            }
            if((*it)->right!=NULL) {
                res.push_back((*it)->right);
            }
        }
        return res;
    }
};