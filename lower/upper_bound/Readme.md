##

-   Given a sorted array, and Q number of queries, check if some given query exists in the array,
    if yes then return Yes {position of the query}, else return the position of the smallest greater number.
-   This problem represents a good exercice for how lower_bound and upper_bound functions work, as well as
    how to make the code run as fast as possible by using the most appropriate data structure for each task.
-   The problem is on hackerrank, at STL problems category.

<br/>
<hr/>
<br/>

### input

-   N: number of integers
-   numbers: sequence of sorted integers
-   Q: number of queries to perform
-   queries: sequence of numbers to check

### output

-   if number exists: print Yes [position ]
-   otherwise: print No [position of the smallest greater number]

<br/>
<hr/>
<br/>

## Example

### sample input

8
1 1 2 2 6 9 9 15
4
1
4
9
15

### simple output

Yes 1
No 5
Yes 6
Yes 8
