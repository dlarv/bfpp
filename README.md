# BrainF*ck++

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
| a-z    | Represents a variable. Move head to cell saved in var.        |
| '      | Move head back to the cell it was at before using a-z.
| (      | Represents the start of a function. Saves instruction pointer into next available fn*. |
| )      | Return instruction pointer to its position before function call. |
| A-Z    | Move instruction pointer to instruction saved in fn.          |
| #      | Print debug state.                                            |

*The hardest problem in programming, as we all know, is naming things. Worry no longer! 