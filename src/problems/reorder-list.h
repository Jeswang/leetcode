//
//  reorder-list.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        int len = 0;
        ListNode *p = head, *previousNode = head, *tempNode = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        
        if (len<=2) {
            return;
        }
        
        int count = 0;
        p = head;
        while (p != NULL) {
            count++;
            tempNode = p->next;
            if (count >= len/2+2) {
                p->next = previousNode;
            }
            previousNode = p;
            p = tempNode;
        }
        
        ListNode *endNode = previousNode, *beginNode = head;
        while (beginNode != endNode) {
            tempNode = beginNode->next;
            beginNode->next = endNode;
            beginNode = tempNode;
            
            if (beginNode == endNode) {
                break;
            }
            
            tempNode = endNode->next;
            endNode->next = beginNode;
            endNode = tempNode;
        }
        
        endNode->next = NULL;
        
        return;
    }
    void run(){
        ListNode *root = listFromString("1->2->3");
        reorderList(root);
        cout<<stringFromList(root);
    }
};