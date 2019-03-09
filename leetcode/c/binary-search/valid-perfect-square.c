#if 0
367. Valid Perfect Square
Easy

409

96

Favorite

Share
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
Accepted
101,050
Submissions
256,422
#endif

bool isPerfectSquare(int num) {
    int n;
    
    if (num == 0)
        return true;
    n = num;
    while (n > num / n) {
        n = ((unsigned long)n + num / n) / 2;
    }
    return n * n == num;
}
