#if 0
344. Reverse String
Easy

672

421

Favorite

Share
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
Accepted
376,164
Submissions
599,414
#endif

void
reverse(char *s, int start, int end)
{
    char *c;
    
    if (start >= end)
        return;
    
    /* recursively increment front and decrement back */
    reverse(s, start + 1, end - 1);
    
    /* swap */
    c = s[start];
    s[start] = s[end];
    s[end] = c;
}

void reverseString(char* s, int sSize) {
    reverse(s, 0, sSize - 1);
}
