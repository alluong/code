#if 0
999. Available Captures for Rook
Easy

19

36

Favorite

Share
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

 

Example 1:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.
Example 2:



Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation: 
Bishops are blocking the rook to capture any pawn.
Example 3:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
The rook can capture the pawns at positions b5, d6 and f5.
 

Note:

board.length == board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'
Accepted
4,056
Submissions
5,356
#endif

bool
check_pos(char **board, int x, int y, int *count)
{
    if (board[y][x] == 'B')
        return true;
    if (board[y][x] == 'p') {
        ++(*count);
        return true;
    }
    return false;
}

int numRookCaptures(char** board, int boardRowSize, int *boardColSizes) {
    int y, x, cur_y, cur_x, count;
    bool found = false;
    
    /* find white Rook */
    x = y = 0;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < boardRowSize; y++) {
            if (board[y][x] == 'R') {
                found = true;
                break;
            } else 
                continue;
        }
        if (found)
            break;
    }
    cur_x = x;
    cur_y = y;
    
    /* white Rook is in position x, y */
    count = 0;
    for (x = cur_x - 1; x >= 0; x--) {
        if (check_pos(board, x, cur_y, &count))
            break;
    }
    for (x = cur_x + 1; x < 8; x++) {
        if (check_pos(board, x, cur_y, &count))
            break;
    }
    for (y = cur_y - 1; y >= 0; y--) {
        if (check_pos(board, cur_x, y, &count))
            break;
    }
    for (y = cur_y + 1; y < boardRowSize; y++) {
        if (check_pos(board, cur_x, y, &count))
            break;
    }
    return count;
}
