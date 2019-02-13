#if 0
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
#endif

int addDigits(int num) {
    /*
     * adding digit means we get a carry if it is greater than 9, so modulo 9
     * gives the correct result
     */
    if (!num)
        return 0;
    return (num % 9 == 0) ? 9 : num % 9;    
}
