//
//  merge-k-sorted-lists.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeTwoList(ListNode *a, ListNode *b) {
        ListNode *res = NULL, *tmp = NULL;
        while(a&&b) {
            if(a->val > b->val) {
                if(!res) {
                    res = b;
                    tmp = res;
                }
                else {
                    tmp->next = b;
                    tmp = b;
                }
                b = b->next;
                tmp->next = NULL;
            }
            else {
                if(!res) {
                    res = a;
                    tmp = res;
                }
                else {
                    tmp->next = a;
                    tmp = a;
                }
                a = a->next;
                tmp->next = NULL;
            }
        }
        if(a&&res){tmp->next = a;return res;}
        if(b&&res){tmp->next = b;return res;}
        
        return a?a:b;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        deque<ListNode *> s;
        for(auto i:lists){s.push_back(i);}
        while(s.size()>1) {
            ListNode *first = s.back();s.pop_back();
            ListNode *second = s.back();s.pop_back();
            ListNode *tmp = mergeTwoList(first, second);
            s.push_front(tmp);
        }
        return (s.size()==0)?NULL:s.back();
    }
};