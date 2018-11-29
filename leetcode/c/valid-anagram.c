/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
bool isAnagram(char* s, char* t) {
    int arr[2][26], ii;
    
    // length has to be the same
    if (strlen(s) != strlen(t))
        return false;
    memset(arr, 0, sizeof(arr));
    while (*s) {
        ++arr[0][*s-'a'];
        ++s;
    }
    while (*t) {
        ++arr[1][*t-'a'];
        ++t;
    }
    for (ii = 0; ii < sizeof(arr[0])/sizeof(arr[0][0]); ii++) {
        if (arr[0][ii] != arr[1][ii])
            return false;
    }
    return true;
}
