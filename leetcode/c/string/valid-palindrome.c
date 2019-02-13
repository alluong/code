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
bool
isPalindrome(char* s) {
    int len, ii, jj;
    char f, b;
    
    if (!s || strlen(s) == 0)
        return true;
    len = strlen(s);
    jj = len - 1;
    for (ii = 0; ii <= len / 2; ii++) {
        f = s[ii];
        
        // convert to lower case
        if (f >= 'A' && f <= 'Z')
            f = tolower(f);
            
        // not alphanumeric
        if ((f < 'a' || f > 'z') && (f < '0' || f > '9'))
            continue;
        b = s[jj];
        if (b >= 'A' && b <= 'Z')
            b = tolower(b);
        while ((b < 'a' || b > 'z') && (b < '0' || b > '9')) {
            // not alphanumeric
            jj--;
            b = s[jj];
            if (b >= 'A' && b <= 'Z')
                b = tolower(b);
        }
        if (f != b) {
            return false;
        }
        --jj;
    }
    return true;
}
