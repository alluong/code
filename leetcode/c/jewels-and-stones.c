/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
int numJewelsInStones(char* J, char* S) {
    int num_jewels;
    int hash[52];
    
    memset(hash, 0, sizeof(hash));
    while (*J) {
        if (*J >= 'a' && *J <= 'z')
            hash[*J - 'a'] = 1;
        else
            hash[*J - 'A' + 26] = 1;
        ++J;
    }
    num_jewels = 0;
    while (*S) {
        if (*S >= 'a' && *S <= 'z') {
            if (hash[*S - 'a'])
                ++num_jewels;
        } else {
            if (hash[*S - 'A' + 26])
                ++num_jewels;           
        }
        ++S;
    }
    return num_jewels;
}
