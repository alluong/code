#if 0
852. Peak Index in a Mountain Array
Easy

239

549

Favorite

Share
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1
Example 2:

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
Accepted
60,284
Submissions
87,301
#endif

int peakIndexInMountainArray(int* A, int ASize) {
    int mid, low, high;
    
    low = 0;
    high = ASize - 1;
    mid = (low + high)/2;
    while (mid > low && mid < high) {
        if (A[mid] > A[mid - 1]) {
            low = mid;
        } else {
            high = mid;
        }                       
        mid = (low + high)/2;
    }
    return mid;
}
