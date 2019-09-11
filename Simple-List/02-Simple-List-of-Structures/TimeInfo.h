/*
 * File name: TimeInfo.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for time information
 */
#ifndef _TIMEINFO_H_
#define _DISPLAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define TIME_SIZE 50

/* Define time structure for fetching records */
typedef struct  
{
	unsigned int hour;
	unsigned int minute;
} FetchTime;

/*
 * This function converts the time_t variable into a string
 *
 * @param[in] time_val - time value in time_t type
 *
 * @returns - time value stored in a string
 */
char* getTimeString(time_t time_val);

/*
 * This function converts the time_t variable into a string
 *
 * @param[in] time_val - time value in time_t type
 *
 * @returns - hour part of time value as an integer
 */
int getTimeHour(time_t time_val);

/*
 * This function converts the time_t variable into a string
 *
 * @param[in] time_val - time value in time_t type
 *
 * @returns - minute part of time value as an integer
 */
int getTimeMinute(time_t time_val);

#endif // _TIMEINFO_H_
