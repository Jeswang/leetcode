//
//  remove-nth-node-from-end-of-list.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }

        p = head;
        ListNode *last = NULL;
        while (count - n != 0) {
            last = p;
            p = p->next;
            count --;
        }
        
        if (last == NULL) {
            return head->next;
        }
        else{
            last->next = p->next;
            return head;
        }
    }
    void run(){
        ListNode *root = listFromString("1->2->3->4->5");
        cout<<stringFromList(removeNthFromEnd(root, 4));
    }
};
