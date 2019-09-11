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

#define ARRAY_FILENAME "arraysdata.txt"
#define BSIZE 50
#define ROW 20
#define COL 20

/*
 * This function reads data from array file
 *
 * returns - nothing
 */
int** readArrayFile(void);

#endif // _LOGFILE_H_
