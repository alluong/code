'''
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
'''

class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        t = ""
        if numRows == 0 or numRows == 1:
            return s
        for ii in range(numRows):
            for jj in range(0, len(s) - ii, 2 * (numRows - 1)):
                if ii % (numRows - 1) == 0 or ii % (2*(numRows - 1)) == 0:
                    # top and bottom row have 1 element
                    t += s[jj + ii]
                else:
                    # middle rows have 2 elements
                    t += s[jj + ii]
                    
                    # make sure we do not go pass the len of string
                    if jj + 2 * (numRows - 1) - ii < len(s):
                        t += s[jj + 2 * (numRows - 1) - ii]
        return t
