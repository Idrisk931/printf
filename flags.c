#include "main.h"

/**
 * get_flags - Extracts active formatting flags from the format string
 * by Joseph and Ciny
 * @format: Formatted string containing the format specifier
 * @i: Pointer to the current position in the format string
 * Return: Combination of flags based on the format specifier
 */
int get_flags(const char *format, int *i)
{
    /* Flags characters and their corresponding bit positions */
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, curr_i;
	int flags = 0;

	/* Iterate through the format string to find active flags */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
	for (j = 0; FLAGS_CH[j] != '\0'; j++)
	{
	/* Check if the current character is a valid flag character */
	if (format[curr_i] == FLAGS_CH[j])
	{
	/* Set the corresponding flag bit */
	flags |= FLAGS_ARR[j];
	break;
	}
	}

	/* If the current character is not a valid flag character, stop searching */
	if (FLAGS_CH[j] == '\0')
	break;
	}

	/* Update the current position in the format string */
	*i = curr_i - 1;

	return (flags);
	}







