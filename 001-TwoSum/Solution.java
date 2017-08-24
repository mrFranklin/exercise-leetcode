/*
* @Author: Franklin
* @Date:   2017-08-24 14:11:32
* @Last Modified by:   Franklin
* @Last Modified time: 2017-08-24 21:06:24
*/

/*
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> positonMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (positonMap.containsKey(nums[i])) {
                return new int[]{positonMap.get(nums[i]), i};
            }
            positonMap.put(target - nums[i], i);
        }
        throw new IllegalArgumentException("No solution");
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] numbers = {3, 2, 4};
        int[] ret = s.twoSum(numbers, 6);
        System.out.println("ret:" + ret[0] + "," + ret[1]);
    }
}