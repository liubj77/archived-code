// Filename: remove_duplicates_from_sorted_list.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

/* Definition for singly-linked list.
 * struct ListNode  {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *begin = head;
        ListNode *end = head;

        while (end) {
            ListNode *tmp = end->next;
            if (tmp == NULL) {  // if the last node
                begin->next = tmp;
                break;
            }
            if (tmp->val == begin->val) {
                end = tmp;
            } else {
                begin->next = tmp;
                begin = tmp;
                end = tmp;
            }
        }

        return head;
    }

};

