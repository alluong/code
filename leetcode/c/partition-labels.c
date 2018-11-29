/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct _arr {
    int start;
    int end;
} arr[26];

int
find_partition(char *s, int start)
{
    int end, ii;
    
    end = arr[s[start]-'a'].end;
    for (ii = start; ii < end; ii++) {
       if (arr[s[ii]-'a'].end > end) {
          end = arr[s[ii]-'a'].end;
       }
    }
    return end;
}

int* partitionLabels(char* S, int* returnSize) {
    int len, start, end, count, ii;
    int result[26], *buf;
    
    memset(arr, -1, sizeof(arr));
    len = strlen(S);
    for (ii = 0; ii < len; ii++) {
        if (arr[*(S+ii)-'a'].start == -1)
            arr[*(S+ii)-'a'].start = ii;
        if (arr[*(S+ii)-'a'].end < ii)
            arr[*(S+ii)-'a'].end = ii;
    }
    start = 0;
    end = 0;
    count = 0;
    while (end < len - 1) {
       end = find_partition(S, start);
       result[count] = end - start + 1;
       start = end + 1;
       ++count;
    }
    *returnSize = count;
    buf = (int *)malloc(count * sizeof(int));
    memcpy(buf, result, sizeof(int) * count);  
    return buf;
}
