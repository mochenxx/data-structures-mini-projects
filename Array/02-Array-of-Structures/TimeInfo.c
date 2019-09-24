#include "TimeInfo.h"

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

char* getTimeString(time_t time_val)
{
	static char time_buffer[TIME_SIZE];
	struct tm* tm_time = localtime(&time_val);	// Local time structure

	// Return a string representing a date and time using tm_time
	strftime(time_buffer, TIME_SIZE, "%Y-%m-%d %H:%M:%S", tm_time);

	return time_buffer;
}

int getTimeHour(time_t time_val)
{
	static char time_buffer[TIME_SIZE];
	struct tm* tm_time = localtime(&time_val);	// Local time structure

	// Return a string representing a date and time using tm_time
	strftime(time_buffer, TIME_SIZE, "%H", tm_time);

	return atoi(time_buffer);
}

int getTimeMinute(time_t time_val)
{
	static char time_buffer[TIME_SIZE];
	struct tm* tm_time = localtime(&time_val);	// Local time structure

	// Return a string representing a date and time using tm_time
	strftime(time_buffer, TIME_SIZE, "%M", tm_time);

	return atoi(time_buffer);
}