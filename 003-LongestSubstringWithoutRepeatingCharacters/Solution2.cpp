/*
* @Author: Franklin
* @Date:   2017-08-26 20:53:03
* @Last Modified by:   Franklin
* @Last Modified time: 2017-08-27 21:01:46
*/

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; // or set lastPos = -1 for the previous postion
        int max = 0;
        map<char, int> cache;
        for (int i = 0; i < s.size(); i++) {
            if (cache.find(s[i]) != cache.end() && cache[s[i]] >= start) {
                start = cache[s[i]] + 1;
            }
            if (i + 1 - start > max) {
                max = i - start;
            }
            cache[s[i]] = i;
        }
        return max;
    }
};

int main() {
    Solution so;
    string s = "abcdefbef";
    int ret = so.lengthOfLongestSubstring(s);
    printf("ret: %d\n", ret);
    
    return 0;
}