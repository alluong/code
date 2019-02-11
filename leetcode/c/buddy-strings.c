#if 0
Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.
#endif

bool buddyStrings(char* A, char* B) {
    int ii, count;
    char a_diff, b_diff, alphabet[26];
    
    /* must have the same length */
    if (strlen(A) != strlen(B)) {
        return false;
    }
    count = 0;
    memset(alphabet, 0, sizeof(alphabet));
    for (ii = 0; ii < strlen(A); ++ii) {
        ++alphabet[A[ii] - 'a'];
        if (A[ii] != B[ii]) {
            ++count;
            switch (count) {
                case 1:
                    a_diff = A[ii];
                    b_diff = B[ii];
                    break;
                case 2:
                    if (A[ii] != b_diff || B[ii] != a_diff) {
                        printf("%c %c %c %c\n", A[ii], b_diff, B[ii], a_diff);
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
    }
    if (count == 0) {
        for (ii = 0; ii < 26; ii++) {
            if (alphabet[ii] >= 2)
                return true;
        }
        if (ii == 26)
            return false;
    }
    return true;
}
