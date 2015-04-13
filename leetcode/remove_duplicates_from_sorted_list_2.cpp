// Filename: remove_duplicates_from_sorted_list_2.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

/*
 * Defination for singly-linked list
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode (int val) : val(x), next(NULL) {}
 * }
 */

class Solution {
public:
    // can use vector store node pointer,
    // here not use vector
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *new_head = NULL;
        ListNode **new_node = &new_head;

        ListNode *begin = head;
        ListNode *end = head;

        int flag = 0; // indicate duplicate flag, 0: false, 1: true

        while (end) {
            ListNode *tmp = end->next;
            if (tmp == NULL) { // last node
                if (flag == 0) {
                    *new_node = begin;
                    new_node = &((*new_node)->next);
                }
                *new_node = NULL;
            }

            if (tmp->val == begin->val) {
                flag = 1;
                end = tmp;
            } else {
                if (flag == 0) { // before has no duplicate nodes
                    *new_node = begin;
                    new_node = &((*new_node)->next);
                }

                begin = tmp;
                end = tmp;
                flag = 0;
            }
        }

        return new_head;
    }
};
