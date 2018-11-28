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
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring
*/
func lengthOfLongestSubstring(s string) int {
    var a [256]byte

    count := 0
    max := 0
    start := 0
    for ii := 0; ii < len(s); ii++ {
        // check if we saw this char before
        if a[s[ii]] != 0 {
            for jj := start; jj < ii; jj++ {
                if s[jj] != s[ii] {
                    a[s[jj]] = 0
                } else {
                    start = jj + 1
                    count = ii - jj
                    break
                }
            }
        } else {
            count++
            a[s[ii]] = 1;
        }
        
        // capture max
        if count > max {
            max = count
        }
    }
    return max
}
