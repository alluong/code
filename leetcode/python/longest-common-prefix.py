"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
"""

class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        # take care empty list
        if len(strs) == 0:
            return ""
        
        # unzip strs and enumerate them
        for num, string in enumerate(zip(*strs)):
            # create a set of string
            length = set(string)
            
            # if length is greater than 1, that means the set has the different
            # characters, return the string up to num
            if (len(length) > 1):
                return strs[0][:num]
            
        # return the shortest string
        return min(strs)
