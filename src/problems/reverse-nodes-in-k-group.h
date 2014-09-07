//
//  reverse-nodes-in-k-group.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=1) {
            return head;
        }
        ListNode *tmp = head;
        bool flag = true;
        
        ListNode *begin = head, *end = NULL, *pBegin = NULL;
        int i = 0;
        
        while(tmp != NULL) {
            i++;
            tmp = tmp->next;
            if(i==k) {
                end = tmp;
                ListNode *tmp2 = swap(begin, end);
                if(flag) {
                    head = tmp2;
                    flag = false;
                }
                else {
                    pBegin->next = tmp2;
                }
                pBegin = begin;
                begin = end;
                i = 0;
            }
        }
        return head;
    }
    
    ListNode *swap(ListNode *begin, ListNode *end) {
        ListNode *tmp = begin->next;
        begin->next = end;
        
        while(tmp!=end) {
            ListNode *tmp2 = tmp->next;
            tmp->next = begin;
            begin = tmp;
            tmp = tmp2;
        }
        return begin;
    }
    void run() {
        ListNode *node = listFromString("1->2->3->4");
        cout<<stringFromList(reverseKGroup(node, 2));
    }
};