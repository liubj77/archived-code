// Filename: add_two_numbers.cpp
// Author: liubj77 - liubj77@gmail.com

/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order 
 * and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = NULL;
        ListNode **node = &res;

        int carry = 0;
        int sum = 0, num1 = 0, num2 = 0;
        while (l1 || l2) {  // length may not equal
            num1 = l1 ? l1->val : 0;
            num2 = l2 ? l2->val : 0;
            sum = num1 + num2 + carry;

            ListNode *temp = new ListNode(sum % 10);

            carry = sum / 10;

            *node = temp;
            node  = &temp->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        if (carry) {
            ListNode *temp = new ListNode(carry);
            *node = temp;
        }

        return res;
    }
};

int main()
{
    ListNode *list_1 = new ListNode(1);
    list_1->next = new ListNode(8);

    ListNode * list_2 = new ListNode(0);

    Solution solution;
    ListNode *temp = solution.addTwoNumbers(list_1, list_2);

    while (temp) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}





