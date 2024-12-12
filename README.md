# BrainF*ck++
An interpreter for BF, with extended syntax. This language is completely backwards compatible with BF and now offers useful features like functions and variables. These saved references are accessed thru a single alphabetical character. So to call function A, you'd just write A. More details can be found below.


## Syntax
| Symbol | Meaning                                          |
|--------|--------------------------------------------------|
| +      | Increment contents of current cell.              | 
| -      | Decrement contents of current cell.              | 
| <      | Move head 1 step to the left.                    | 
| >      | Move head 1 step to the right.                   | 
| .      | Print character under head.                      |
| ,      | Receive input from stdin and write its value to current cell. |
| [      | If contents of current cell is zero, jump to next ].          |
| ]      | If contents of current cell is non-zero, jump to prev [.      |
| =      | Saves a reference to current cell into next available var*.   |
| a-z    | Move head to cell saved in var.        |
| '      | Move head back to the cell it was at before using a-z.
| (      | Saves instruction pointer into next available fn*. |
| )      | Return instruction pointer to its position before function call. |
| A-Z    | Move instruction pointer to instruction saved in fn.          |
| #      | Print debug state.                                            |

*The hardest problem in programming, as we all know, is naming things. Worry no longer! With BF++, the interpreter will take care of naming variables and functions for you! Your first variable can be found by using 'a', your second by 'b', and so forth. Functions are the same, except they use uppercase. If you need more than 26 functions or variables, you should probably optimize your code better...

## Examples

