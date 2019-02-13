/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
int lengthOfLongestSubstring(char* s) {
    int len, ii, jj, kk;
    int count, max, start;
    char a[256];

    count = 0;
    max = 0;
    len = strlen(s);
    memset(a, 0, sizeof(a));
    start = 0;
    for (ii = 0; ii < len; ii++) {
        // check if we saw this char before
        if (a[s[ii]]) {
            for (jj = start; jj < ii; jj++) {
               if (s[jj] != s[ii]) {
                  a[s[jj]] = 0;
               } else {
                  start = jj + 1;
                  count = ii - jj;
                  break;
               }
            }
        } else {
           ++count;
           a[s[ii]] = 1;
        }

        // capture the max count
        if (count > max) {
            max = count;
        }
    }
    return max;
}
