HOMEWORK 10:  PERFORMANCE & BIG O NOTATION


NAME:  Abby Itty


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

Discord, cplusplus, geeksforgeeks, Kyle F, Zixiang

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  30? ish?



COMPLEXITY ANALYSIS
n = number of elements in the input
f = requested number of values in output (first sorted only)
l = maximum length of any string element

Neatly fill in the table below with the Big O Notation for running time.

------------------------------------------------------------------------------
|          |          | remove   |          | closest  | first f  | longest  |
|          | sort     | dups     | mode     | pair     | sorted   | substr   | 
------------------------------------------------------------------------------
|          | O(nlogn) |  O(n^2)  |O(nlogn)  | O(nlogn) |O(f+nlogn)|O(n^2 l^2)|
| vector   |          |          |          |          |          |          |
------------------------------------------------------------------------------
|          | O(nlogn) |  O(n^2)  |O(nlogn)  |O(nlogn)  |O(f+nlogn)|O(n^2 l^2)|
| list     |          |          |          |          |          |          |
------------------------------------------------------------------------------
|          | O(nlogn) | O(nlogn) | O(nlogn) | O(nlogn) | O(nlogn) |O(n^2 l^2)|
| bst      |          |          |          |          |          |          |
------------------------------------------------------------------------------
|          |   O(1)   |   O(n)   |   O(n)   |  O(n)    |  O(1)    |    X     |
| pq       |          |          |          |          |          |          |
------------------------------------------------------------------------------
|          |     X    |   O(1) n?|   O(n)   |  O(n^2)  |    X     |O(n^2 l^2)|
| hash     |          |          |          |          |          |          |
------------------------------------------------------------------------------



RESULTS
For each data type and each operation, run several sufficiently large
tests and collect the operation time output by the program. Organize
these timing measurements in your README.txt file and estimate the
coefficients for the dominant term of your Big ‘O’ Notation.

vector: 5.46 * 10^-8

sort:					remove_duplicates:
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0			10,000		0.796875
20,000		0.015625		20,000		3.125
50,000		0.03125			50,000		19.7344
100,000		0.0625			100,000		79.25

mode:					closest_pair(int only):
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0			10,000		0
20,000		0.015625		20,000		0
50,000		0.03125			50,000		0.015625
100,000		0.078125		100,000		0.046875

first_sorted:				longest_substring:
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0.015625		10,000		15.1562
20,000		0.015625		20,000		62
50,000		0.046875		50,000		391.703
100,000		0.0625			100,000		1590.19


list:

sort:					remove_duplicates:
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0.015625		10,000		1.53125
20,000		0.015625		20,000		5.85938
50,000		0.046875		50,000		36.1875
100,000		0.109375		100,000		143.703

mode:					closest_pair(int only):
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0			10,000		0.015625
20,000		0.015625		20,000		0.015625
50,000		0.046875		50,000		0.03125
100,000		0.125			100,000		0.09375

first_sorted:				longest_substring:
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0			10,000		67.5156
20,000		0.015625		20,000		
50,000		0.046875		50,000		
100,000		0.109375		100,000		

bst:

sort:					remove_duplicates:
input #:	time(sec):		input #:	time(sec):
11		0			11		0
10,000		0.015625		10,000		0.0625
20,000		0.015625		20,000		
50,000		0.0625			50,000		
100,000		0.125			100,000		


DISCUSSION
Do these measurements and the overall performance match your predicted
Big ‘O‘ Notation for the data type and operation? Did you update your
initial answers for the Big ‘O‘ Notation of any cell in the table?

Compare the relative coefficients for different data types that have
the same Big ‘O’ Notation for a specific operation. Do these match
your intuition? Are you surprised by any of the results? Will these
results impact your data structure choices for future programming
projects?

Use well-written, complete sentences.  Approximately 250-500 words.  


My coefficients roughly matched most of my big O guesses! I did end up changing
a lot of the priority queue row especially because I didn't understand that
I had to factor in the creation of the queue as well as the complexity for
each specific function. I was surprised that on average, vector is faster than
list. I thought because of the pointers and the non-continuous memory, vectors
would be faster.



MISC. COMMENTS TO GRADER:  
I ran out of time on some of the charts, but I'll try to get as many in as I can!
