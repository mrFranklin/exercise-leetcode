/*
* @Author: Franklin
* @Date:   2017-08-24 16:21:51
* @Last Modified by:   Franklin
* @Last Modified time: 2017-08-24 16:27:45
*/

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                ret.push_back(left + 1);
                ret.push_back(right + 1);
                break;
            } else {
                if (numbers[left] + numbers[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return ret;
    }
};

int main(){
    int a[] = {2, 3, 4};
    vector<int> v(a, a + 3);
    Solution s;
    vector<int> ret = s.twoSum(v, 7);
    printf("ret: %d, %d\n", ret[0], ret[1]);
    return 0;
}
