/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
import "strings"

func isPalindrome(s string) bool {
    var ii, jj int
    var f, b byte
    
    // null string
    if len(s) == 0 {
        return true
    }
    jj = len(s) - 1
    s = strings.ToLower(s)
    for ii = 0; ii <= len(s) / 2; ii++ {
        f = s[ii]

        // alphanumeric?
        if (f < 'a' || f > 'z') && (f < '0' || f > '9') {
            continue
        }
        b = s[jj]
        for ; (b < 'a' || b > 'z') && (b < '0' || b > '9'); {
            // not alphanumeric
            jj--
            b = s[jj]
        }
        if f != b {
            return false
        }
        jj--
    }
    return true
}
