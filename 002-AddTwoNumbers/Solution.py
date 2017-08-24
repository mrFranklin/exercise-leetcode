# -*- coding: utf-8 -*-
# @Author: Franklin
# @Date:   2017-08-24 20:19:24
# @Last Modified by:   Franklin
# @Last Modified time: 2017-08-24 20:53:49

'''
https://leetcode.com/problems/add-two-numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''
# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        dummy = ListNode(0)
        p = dummy
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            data = val1 + val2 + carry
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

            p.next = ListNode(data % 10)
            p = p.next

            carry = data / 10

        return dummy.next

s = Solution()
l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)
l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)
ret = s.addTwoNumbers(l1, l2)
while ret:
    print "ret:" + str(ret.val)
    ret = ret.next

