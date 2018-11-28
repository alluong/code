/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
int reverse(int x) {
    long val; // needs to be long because result could be bigger than int
    
    val = 0;
    while (x) {
        val = val * 10 + x % 10;
        x = x / 10;
    }
    if (val > INT_MAX || val < -INT_MIN)
        return 0;
    return val;
}
