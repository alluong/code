"""
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
"""
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
   
        mappings = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }
        if not len(digits):
            return []
        result = [""]

        # for digit in digits:
        #    result = [combo+letter for combo in result for letter in mappings[digit]]

        for digit in digits:
            # digit 2 and 3
            combs = []
            for combo in result:
                #print("combo", combo, "digit", digit, "result", result)
                for letter in mappings[digit]:
                    #print("letter", letter, "combo", combo, "digit", digit, "result", result)
                    combs.append(combo + letter)
            #print("before", result, combs)
            result = combs
            #print("after", result)
        return result
