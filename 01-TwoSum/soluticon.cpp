/*
* @Author: Franklin
* @Date:   2017-08-24 12:56:29
* @Last Modified by:   zhangbin
* @Last Modified time: 2017-08-24 14:02:39
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


#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> positonMap;
        for (int i = 0; i < nums.size(); i++) {
            if (positonMap.find(nums[i]) != positonMap.end()) {
                ret.push_back(positonMap[nums[i]]);
                ret.push_back(i);
                break;
            } else {
                positonMap[target - nums[i]] = i;   
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    // int a[] = {2, 7, 11, 15};
    int a[] = {3, 2, 4};
    vector<int> v(a, a + 3);
    Solution s;
    vector<int> ret = s.twoSum(v, 6);
    printf("ret: %d, %d\n", ret[0], ret[1]);

    return 0;
}