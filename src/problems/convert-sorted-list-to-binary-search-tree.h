//
//  convert-sorted-list-to-binary-search-tree.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode* pointer = head;
        while(pointer!=NULL) {
            len++;
            pointer = pointer->next;
        }
        return realSortedListToBST(head, len);
    }
    
    TreeNode *realSortedListToBST(ListNode *head, int len) {
        if (len == 0) {
            return NULL;
        }
        
        if (len == 1) {
            return new TreeNode(head->val);
        }
        
        ListNode* pointer = head;
        int half = (len-1)/2;
        while(half > 0) {
            half--;
            pointer = pointer->next;
        }
        
        TreeNode* newHead = new TreeNode(pointer->val);
        newHead->left = realSortedListToBST(head, (len-1)/2);
        newHead->right = realSortedListToBST(pointer->next, len-1-(len-1)/2);
        
        return newHead;
    }
    void run() {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(3);
        sortedListToBST(head);
    }
};