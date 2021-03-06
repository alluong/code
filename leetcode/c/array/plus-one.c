/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * (digitsSize + 1));
    int ii, add, carry = 0;
    
    add = 1;
    for (ii = digitsSize - 1; ii >= 0; ii--) {
        arr[ii + 1] = (digits[ii] + add + carry) % 10;
        carry = (digits[ii] + add + carry) / 10;
        add = 0;
    }
    arr[0] = carry;
    if (carry) {
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
        for (ii = 0; ii < digitsSize; ii++) {
            arr[ii] = arr[ii + 1];
        }
    }
    return arr;    
}
