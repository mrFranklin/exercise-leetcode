/*
* @Author: Franklin
* @Date:   2017-08-24 17:24:30
* @Last Modified by:   Franklin
* @Last Modified time: 2017-08-24 20:18:28
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void setNextDataAndMove(ListNode **header, ListNode **p, int data) {
        ListNode *node = new ListNode(data);
        if ((*header) == NULL) {
            *header = node;
            (*p) = node;
        } else {
            (*p)->next = node;
            (*p) = (*p)->next;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lRet = NULL;
        ListNode* p = lRet;
        int carry = 0;
        int data;
        while(l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                data = l2->val + carry;
                l2 = l2->next;
            } else if (l2 == NULL) {
                data = l1->val + carry;
                l1 = l1->next; 
            } else {
                data = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next; 
            }
            setNextDataAndMove(&lRet, &p, data % 10);
            carry = data / 10;
        }

        if (carry != 0) {
            setNextDataAndMove(&lRet, &p, carry);
        }

        return lRet;
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