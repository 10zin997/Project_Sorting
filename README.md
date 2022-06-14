# DATA Structure Project 1
## Sorting - collecting stats and counts using sorting algorithms.

The main program will continue the following until the end of the set of data...

1. Call a subprogram to read a group of numbers to be sorted
2. Call a subprogram to sort these values using three sorts
3. Call a subprogram to compare the three sorts

STEP 1: The read subprogram will first read a heading describing the group of
numbers (e.g. the heading might be: 10 numbers in order, or 50 numbers in
random order or 100 numbers in reverse order).  Then it will read in the group
of numbers. The original group should be printed as it is read in.

STEP 2: The three sort subprogram will call three separate sorts (be sure to send
each one the items in their original order):

    a. One sort will be a stupid one - either linear or bubble
    b. One sort will be quiksort
    c. One sort will be any other good one of your choice (e.g. heapsort)

After each individual sort subprogram finishes, the sorted array should be printed.
Also print the number of comparisons each sort needed and the (number) of times
elements were interchanged. (These values must be computed with the three individual
sorting subprograms. Use either additional parameters or global variables, but be
sure to include comments.)

STEP 3: The comparison subprogram will determine which sort used the most comparisons,
which was in the middle, and which used the least. It will do the same thing for
interchanges.

DATA: Remember that each group of data must start with a heading describing what it
is testing. You are allowed to have repeats in the group, but there should not be too
many repeated values. You should include at least the following 9 groups.
(the heading for a group can be what I used to describe it):

1. 10 numbers in almost sorted order (two or three numbers interchanged)
2. 10 numbers in random order
3. 10 numbers in reverse order
4. 50 numbers in almost sorted order (a few out of order)
5. 50 numbers in random order
6. 50 numbers in reverse order
7. 100 numbers in almost sorted order (a few out of order)
8. 100 numbers in random order
9. 100 numbers in reverse order
