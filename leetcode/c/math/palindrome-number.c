/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
bool isPalindrome(int x) {
    long val, tmp;
    
    /* check if x is negative */
    if (x < 0)
        return false;
    val = 0;
    tmp = x;
    
    /* reverse x */
    while (tmp) {
        val = val * 10 + tmp % 10;
        tmp /= 10;
    }
    if (val == x)
        return true;
    return false;
}
