#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
display(int **arr, int num)
{
    int ii, jj, *row;

    row = (int *)&arr[0];
    for (ii = 0; ii < num; ii++) {
        for (jj = 0; jj < num; jj++) {
            printf("%3d ", row[ii * num + jj]);
        }
        printf("\n");
    }
}

void
get_next(int **arr, int num, int *x, int *y)
{
    int *tmp;

    if (*x < 0 && *y < 0) {
        *x = *y = 0;
        printf("init\n");
        return;
    }

    /* 4 cases - right, down, left, up */
    /*
     * case 1: see if we can move right
     */
    tmp = (int *)&arr[0];

    /* if we are not at the last column and the right is not occupied */
    if (*x < num - 1 && *(tmp + num * (*y) + *x + 1) == 0) {
        /* check to see if top is occupied */
        if (*y > 0 && *(tmp + num * (*y - 1) + *x) == 0) {
            printf("up\n");
            --*y;
        } else {
            /* move right */
            printf("right\n");
            ++*x;
        }
    } else if (*y < num - 1 && *(tmp + num * (1 + *y) + *x) == 0) {
        /* bottom is not occupied */
        /* move down */
        printf("down\n");
        ++*y;
    } else if (*x > 0 && *(tmp + num * (*y) + *x - 1) == 0) {
        /* left is not occupied */
        /* move left */
        printf("left\n");
        --*x;
    } else {
        /* last option */
        printf("up\n");
        --*y;
    }
}

void
spiral(int num, int **arr)
{
    int     x, y, ii, *tmp;

    x = -1;
    y = -1;
    for (ii = 1; ii <= num * num; ii++) {
        get_next(arr, num, &x, &y);
        tmp = (int *)&arr[0];
        tmp[y * num + x] = ii;
    }
}

int
main(void)
{
    int **arr, ii, jj, num;

    num = 10;

    /* allocate and clear memory */
    arr = (int **)malloc(sizeof(int) * num * num);
    memset(arr, 0, sizeof(int) * num * num);

    /* call spiral */
    spiral(num, arr);

    /* display */
    display(arr, num);
}
