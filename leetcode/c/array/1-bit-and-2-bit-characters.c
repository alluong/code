#if 0
717. 1-bit and 2-bit Characters
Easy

229

572

Favorite

Share
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
Accepted
35,735
Submissions
73,158
#endif

bool isOneBitCharacter(int* bits, int bitsSize) {
    int last, ii, count;
    
    if (!bitsSize)
        return false;
    last = bits[bitsSize - 1];
    if (last == 1)
        return false;
    
    /* start from the next to last bit and count the number of 1 bits */
    count = 0;
    for (ii = bitsSize - 2; ii >= 0; ii--) {
        if (bits[ii] == 1)
            ++count;
        else
            break;
    }
    if (count % 2 == 0)
        return true;
    return false;
}
