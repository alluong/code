func isIdealPermutation(A []int) bool {
    var ii int

    for ii = 0; ii < len(A); ii++ {
        if A[ii] - ii >= 2 || ii - A[ii] >= 2 {
            return false
        }
    }
    return true
}
