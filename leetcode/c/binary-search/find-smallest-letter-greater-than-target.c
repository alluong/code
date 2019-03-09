#if 0
744. Find Smallest Letter Greater Than Target
Easy

193

291

Favorite

Share
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.
Accepted
35,030
Submissions
80,401
#endif

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int low, high, mid;
    
    /* check for wraparound */
    if (target < letters[0] || target >= letters[lettersSize - 1])
        return letters[0];
    low = 0;
    high = lettersSize - 1;
    mid = (low + high) / 2;
    while (low < mid && mid < high) {
        if (target >= letters[mid]) {
            low = mid;
        } else {
            high = mid;
        }
        mid = (low + high) / 2;
    }
    if (target < letters[mid])
        return letters[mid];
    return letters[mid + 1];
}
