# -*- coding: utf-8 -*-
# @Author: Franklin
# @Date:   2017-08-24 15:41:52
# @Last Modified by:   Franklin
# @Last Modified time: 2017-08-24 16:09:26

"""
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
"""

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = [];
        positionMap = {}
        for i in range(len(nums)):
            if positionMap.has_key(nums[i]):
                ret.append(positionMap[nums[i]])
                ret.append(i)
            else:
                positionMap[target - nums[i]] = i

        return ret
        
s = Solution()
ret = s.twoSum([1, 2, 3], 5)
print "ret:" + str(ret)

