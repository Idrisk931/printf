#include "main.h"

/*
 * get_precision - Calculates the precision for printing.
 *
 * This function analyzes a formatted string and extracts the precision
 * value specified within it. The precision value is used for printing
 * purposes and is typically indicated by a period followed by digits
 * or an asterisk in the format string.
 *
 * @format: The formatted string containing the print format.
 * @i: A pointer to the current position in the format string.
 * @list: The list of arguments for the formatted string.
 *
 * Return: The extracted precision value.
 *
 */
	int get_precision(const char *format, int *i, va_list list)
	{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
