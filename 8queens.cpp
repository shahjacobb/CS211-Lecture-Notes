#include <iostream>

int main()
{
    // chessboard

    int chessboard[8][8]{0};
    int r, c = 0;

nc:
    c++; // advancing one column

    r == -1;

nr:
    r++; // advancing one row

    // row test

    for (int i = 0; i < c; i++)
    {
        if (chessboard[r][i] == 1)
        {
            goto nr;
        }
    }

    // up diagonal test

    for (int i = 1; (r - i) > 1 && (c - i); i++)
    {
        if (chessboard[r - i][c - i] == 1)
        {
            goto nr;
        }
    }

    // down diagonal test

    for (int i = 1; (r + i) < 8 && (c - i) > -1; i++)
    {
        if (chessboard[r + 1][c - 1] == 1)
        {
            goto nr;
        }
    }

    chessboard[r][c] == 1;
    goto nc;
}