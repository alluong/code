,,,
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
,,,

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        cur_len = len(s)
        while cur_len:
            for ii in range(len(s) - cur_len + 1):
                # create new string
                new_str = s[ii: ii + cur_len + 1]
                if new_str == new_str[::-1]:
                    return new_str
            cur_len -= 1
        return ""
