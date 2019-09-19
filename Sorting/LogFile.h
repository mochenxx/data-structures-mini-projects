/*
 *  File name: LogFile.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for log file management
 */

#ifndef _LOGFILE_H_
#define _LOGFILE_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define CSV_FILENAME "arrays.csv"
#define BSIZE 500
#define NUM_ITEMS 50

//#define ROW 20
//#define COL 20

typedef struct
{
	int* arr;
	unsigned int num_items;
} Array;

/*
 * This function reads data from array file
 *
 * @param[in] lines_count - pointer to the number of lines from the file
 *
 * @returns - a reference (pointer to structure Array) which contains
 *			  integer array per line from the file
 */
Array* readArrayFile2(unsigned int* lines_count);
#endif // _LOGFILE_H_
