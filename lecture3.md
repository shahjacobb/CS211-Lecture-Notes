# Lecture 4

## Setting the stage

What **data structure** are we using? We're going to **use a 2-D array.** This lets us easily represent a chess board. And we*could*
fill the chess board is by using either `bool` or `short`, because those are 1 byte each. But for the sake of the class, we'll go with `int`.



Remember that it's __COLUMN and then ROW__. We're moving down each __row COLUMN BY COLUMN__. We're
*not* moving from row to row and iterating across the columns like you would in a 2D array.

How do we move one column forward or row forward? Assuming we set our `row` and `column` variables to `r` and `c`, the increment operator (or just `var + 1`) works. So `c++` moves forward one column (haha, `c++`, get it?)

```cpp
// first, we need to set the 'initial state' of the board like:

int b[8][8] {0};
int r = 0, c;
```
Then we need to move to the next column as stated before, right? Since we successfully placed a queen in the first column. So we need to move to the __next column__, which will look like `c++` (next column). And remember, this consists of two loops: 1) an outer loop moving across colums and an inner loop iterating down the rows. 
```cpp

c++; // next column (outer loop)
r = -1;

r++;  // next row (inner loop)

```
Why tf is `r` being set to `-1`? The reason is that when the r++ increment happens, `r++` will add `1` to our variable, and since the index starts at 0 in cpp arrays, we have to set it with `-1`.

## What things do we have to satisfy
- __The Row **Test__**
  - In the row test, we set the for loop conditions for `i = 0` (obviously), and `i < c`, and then `i++`. I know what you're thinking - wait, what? Why not `i--`? We're moving left-wards to check every column in that row, right? Well it doesn't matter if we're moving left or right.
  - Remember that we're **MOVING ACROSS COLUMNS** when doing the row test, so `[c]` is going to change, not `[r]`. So when we do the check, we're checking against `c` in our for loop. And then, we set the chessboard to 'slide' against the column when doing the check in the for loop using `chessboard[r][i]`. Rememmber, again, that `c` is going to change and not `r`, so that's why `[c]` is replaced with `[i]`. 
  - If a position is filled with a Queen, remember that we're using 1. So if `chessboard[r][i] == 1`, that's not good. We'll have to move to the next row using goto, for now.  
- __The Up Diagonal Test__
  - If we failed the row test above (aka, `chessboard[r][i]==1`), then the program goes to go `goto nr`, where it moves down
- __The Down Diagonal Test__
  - d

```cpp
// row test
nr: for (int i = 0; i < c; i++)
{
  if (chessboard[r][i] == 1)
  {
    goto nr;
  }
}
{


}
// up diag test
for int i = 0; (r-w) > -1 && (c-i) >> 1; i++) 
{
  if(b[r-1][c-1] == 1) 
  {
    goto nr;
  }   
}

// down diag test 
```
### `goto` statements
ddd

```
// some pseudocode for what it would look like

a: void foo()
{
    dosomething
}

if (condition)
{
    goto b;
}

goto a

goto b;
```