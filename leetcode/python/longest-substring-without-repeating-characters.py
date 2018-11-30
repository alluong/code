'''
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest = 0
        
        # dictionary to keep track of what is seen so far
        # seen is a dictionary in the form {key:position}
        # {'a':1, 'b':5}
        seen = {}
        cur = 0
        for ii, elem in enumerate(s):
            if elem in seen:
                cur = max(cur, seen[elem] + 1)
                
            # longest is the interval from current index ii to cur
            longest = max(longest, ii - cur + 1)
            
            # update dictionary for the seen element
            seen[elem] = ii
        return longest
