#if 0
167. Two Sum II - Input array is sorted
Easy

787

333

Favorite

Share
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Accepted
210,967
Submissions
428,705
#endif

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *arr = malloc(sizeof(int) * 2);
    int ii, jj;

    *returnSize = 2;
    ii = 0;
    jj = numbersSize - 1;
    while (ii < jj) {
        if (numbers[ii] + numbers[jj] == target)
            break;
        if (numbers[ii] + numbers[jj] < target)
            ii++;
        else
            jj--;
    }
    arr[0] = ii + 1;
    arr[1] = jj + 1;
    return arr;
}
