"""
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
"""

class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        # check row
        for row in range(9):
            seen = []
            for col in range(9):
                if (board[row][col] != '.'):
                    seen += board[row][col]
            if (len(seen) != len(set(seen)) and len(seen) != 0):
                return False
        
        # check column
        for col in range(9):
            seen = []
            for row in range(9):
                if (board[row][col] != '.'):
                    seen += board[row][col]
            if (len(seen) != len(set(seen)) and len(seen) != 0):
                return False
            
        # check box
        for row_index in range(3):
            for col_index in range(3):
                seen = []
                for row in range(3 * row_index, 3 * row_index + 3):
                    for col in range(3 * col_index, 3 * col_index + 3):
                        if (board[row][col] != '.'):
                            seen += board[row][col]
                if (len(seen) != len(set(seen)) and len(seen) != 0):
                    return False
        return True
