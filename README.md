Project rules
• The Project is composed of 2 stacks named "a" and "b".
"a" contains a random number of either positive or negative numbers without
any duplicates, "b" is empty. The goal is to sort in ascending order numbers
into stack "a".

 To do this you have the following operations at your disposal:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

rrr : rra and rrb at the same time.

  Push_swap will receive as an argument the stack "a" formatted as a list of integers.
The first argument should be at the top of the stack
 
  Checker will get as an argument the stack "a" formatted as a list of integers. 
The first argument should be at the top of the stack (be careful about the order). If 
no argument is given checker stops and displays nothing. Checker will then wait and 
read instructions on the standard input, each instruction will be followed by ’\n’. 
Once all the instructions have been read, checker willexecute them on the stack received 
as an argument. If after executing those instructions, stack a is actually sorted and b 
is empty, then checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.

  To run visualization add flag -v after numbers in push_swap, best visualization is for 100
numbers, smaller will be too fast, window will be closed automatically after end of sorting
algoritm.

  Progect was done on double linked lists, was realized fast half sort with central element
