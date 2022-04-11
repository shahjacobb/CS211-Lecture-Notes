# 8 Queens Solution With Goto

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

nc: c++; 
r = -1;
nr: r++; 

```
Why tf is `r` being set to `-1`? The reason is that when the r++ increment happens, `r++` will add `1` to our variable, and since the index starts at 0 in cpp arrays, we have to set it with `-1`.

But the __REAL__ reason is that let's say all 3 tests above 'pass' (in other words, all the if statements were false). If that's the case, we move end up triggering `go to nc`. Since we want start at the top again, we need to set r to 0 AFTER the `nc` label. (Tbh, I'm not sure on this one).
## What things do we have to satisfy
- __The Row **Test__**
  - In the row test, we set the for loop conditions for `i = 0` (obviously), and `i < c`, and then `i++`. I know what you're thinking - wait, what? Why not `i--`? We're moving left-wards to check every column in that row, right? Well it doesn't matter if we're moving left or right.
  - Remember that we're **MOVING ACROSS COLUMNS** when doing the row test, so `[c]` is going to change, not `[r]`. So when we do the check, we're checking against `c` in our for loop. And then, we set the chessboard to 'slide' against the column when doing the check in the for loop using `chessboard[r][i]`. Rememmber, again, that `c` is going to change and not `r`, so that's why `[c]` is replaced with `[i]`. 
  - If a position is filled with a Queen, remember that we're using 1. So if `chessboard[r][i] == 1`, that's not good. We'll have to move to the next row using goto, for now.  
- __The Up Diagonal Test__
  - If we failed the row test above (aka, `chessboard[r][i]==1`), then the program goes to go `goto nr`, where it moves down
- __The Down Diagonal Test__
- T
```cpp

nc: c++
nr: r++
// gdfgfdgdf missing if statement here 

// row test
for (int i = 0; i < c; i++)
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

for(int i = 0; ; i++)
{
  if(b[r+i][c-i) == 1)
  {
    goto nr;
  }
}

```

Once we're done doing all the tests, if all 3 if statements (because they're just if statements fail, we place a queen into the board at that position using `chessboard[r][c] == 1`.

After that, we move on to the next row by making the compiler go to the `nr` label where it says `c++`.

__One point of confusion__: `r` and `c` values are actually changing - remember that the `variable++` thing is just syntactic sugar for `variable = variable + 1`. In other words, ___the changes are stored in place___. 



## What Next After The 3 Checks: Preventing an Infinite Loop
Once we're done with that, keep in mind that there's only 8 rows on the board. So even if the program keeps successfully getting past the 3 checks, `goto nc` at the end of the checks before pretty much creates an infinite loop, and because `goto` statements are an unconditional jump, we'll need an if statement to make the program end. And that goes before `nr`.

```cpp
if (c ==)
```
d
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