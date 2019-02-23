#if 0
896. Monotonic Array
Easy

199

20

Favorite

Share
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
Accepted
32,031
Submissions
58,799
#endif

bool isMonotonic(int* A, int ASize) {
    bool ret = true, increase = false, decrease = false;
    int ii;
    
    for (ii = 0; ii < ASize - 1; ii++) {
        if (A[ii + 1] > A[ii])
            increase = true;
        else if (A[ii + 1] < A[ii])
            decrease = true;
        if (increase && decrease)
            return false;
    }
    return true;
}
