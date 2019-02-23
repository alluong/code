#if 0
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

 

Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8
 

Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6
Accepted
9,578
Submissions
16,859
#endif

int cmpfunc (const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int largestPerimeter(int* A, int ASize) {
    int a2, a1, a0, ii;
    
    if (ASize < 3)
        return 0;
    
    /* sort array using qsort */
    qsort(A, ASize, sizeof(A[0]), cmpfunc);
    
    /* try the largest 3 elements */
    for (ii = ASize - 1; ii >= 2; ii--) {
        a0 = A[ii];
        a1 = A[ii - 1];
        a2 = A[ii - 2];
        
        /*
         * if the other 2 sides are longer than the longest side, we have a valid
         * triangle
         */
        if (a0 < a1 + a2)
            return a0 + a1 + a2;
    }
    return 0;
}
