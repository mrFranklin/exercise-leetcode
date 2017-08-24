/*
* @Author: Franklin
* @Date:   2017-08-24 17:24:30
* @Last Modified by:   Franklin
* @Last Modified time: 2017-08-24 21:17:21
*/

/*
https://leetcode.com/problems/add-two-numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curNode = dummy;
        int carry = 0;
        int data;
        while(l1 != NULL || l2 != NULL) {
            int x1 = (l1 != NULL) ? l1->val : 0;
            int x2 = (l2 != NULL) ? l2->val : 0;
            data = x1 + x2 + carry;

            curNode->next = new ListNode(data % 10);
            curNode = curNode->next;

            carry = data / 10;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry > 0) {
            curNode->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *ret = s.addTwoNumbers(l1, l2);
    while (ret != NULL) {
        printf("%d\n", ret->val);
        ret = ret->next;
    }
    
    return 0;
}