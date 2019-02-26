#if 0
605. Can Place Flowers
Easy

415

242

Favorite

Share
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
Accepted
52,865
Submissions
172,366
#endif

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int ii, running_zero, avail;
    
    running_zero = 1;
    avail = 0;
    for (ii = 0; ii < flowerbedSize; ii++) {
        if (flowerbed[ii] == 0)
            ++running_zero;
        else {
            avail += (running_zero  - 1)/ 2;
            running_zero = 0;
        }
    }
    avail += running_zero / 2;
    if (n <= avail)
        return true;
    return false;
}
