# Data Structures Mini Projects
Data structures mini projects for learning sharing.

## Table of Contents

- [Compatability](#compatability)
- [Projects](#projects)
- [Contact](#contact)

## Compatability

- Operating System: Windows 10
- Compiler: Microsoft Visual C++ 2019

## Projects
### Sorting project

- This program creates four standard sorting algorithms: 
  * Selection Sort
  * Insertion Sort
  * Bubble Sort
  * Merge Sort 
- Optimized approaches are added to improve sorting performance in terms of time complexity
- Program can sort array through two ways:
  * Input an integer array from keyboard
  * Read stored arrays from a txt file
- C Source Code: [Sorting](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Sorting)

### Simple list project

This projects achieves two goals in terms of simple lists, and implements frequently-used operations for lists.

- C Source Code
  * [Simple list of integers](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Simple-List/01-Simple-List-of-Integers)
  * [Enhanced simple list of structures](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Simple-List/02-Simple-List-of-Structures)
  
__Goal-1: Create a simple list of integers__
- This list stores a list of integer values given by user input.
- Available operations are as follows: 
  * Add an element to the list - `Input element must be unique`
  * Delete an element from the list - `Need to enter an element value to be deleted`
  * Clear all elements in the list
  * Get Sum of all elements in the list
  * Print all elements in the list
- A List has the following properties:
  * list pointer
  * list size (from program input)
  * list count (number of elements in the list)

__Goal-2: Enhance simple list__
- Thie list stores a list of user-defined structures that contains not only integer values but the time of element addition.
- Therefore, program can diffference the sequence of each element based on stored time value.
- A List has the following properties:
  * list pointer
  * list size (from program input)
  * list count (number of elements in the list)
  * list current index (index of last element added to the list)
- In addition to deleting a specific element(the 2nd operation as above), two more operations are considered: 
  * Delete last added element
  * Delete oldest added element
- Program is also capable to fetch records within certain time requirements
  * Fetch records after a time (e.g., 9:00)
  * Fetch records before a time (e.g., 16:00)
  * Fetch records between a time interval (e.g., b/w 11:00 and 12:00)

## Contact

You can reach me at mo.chen19@outlook.com for technical support or feel free to open an issue [here](https://github.com/mochenxx/data-structures-mini-projects/issues) :)
