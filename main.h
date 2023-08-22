#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x) /* Macro to suppress unused variable warnings */
#define BUFF_SIZE 1024      /* Buffer size for printing operations */

/* Flags used for formatting */
#define F_MINUS 1   /* Flag for left-justification */
#define F_PLUS 2    /* Flag to display plus sign for positive numbers */
#define F_ZERO 4    /* Flag to pad with zeroes */
#define F_HASH 8    /* Flag to add '0x' or '0X' for hexadecimal values */
#define F_SPACE 16  /* Flag to add a space before positive numbers */

/* Size indicators for integers */
#define S_LONG 2    /* Indicates 'long' size modifier */
#define S_SHORT 1   /* Indicates 'short' size modifier */

/**
 * struct fmt_info - Structure for format information
 *
 * @fmt: The format specifier character.
 * @func_ptr: Pointer to the associated printing function.
 */
struct fmt_info
{
        char fmt;
        int (*func_ptr)(va_list, char[], int, int, int, int);
};

/**
 * Typedef for struct fmt_info - Format information structure.
 */
typedef struct fmt_info fmt_info_t;

/* Main printing function */
int my_printf(const char *format, ...);

/* Handles the formatting and printing of different data types */
int handle_print(const char *fmt, int *i,
        va_list list, char buffer[], int flags, int width, int precision, int size);

/** FUNCTIONS **/

/* Functions for printing characters and strings */
int print_character(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Functions for printing different number bases */
/*...(similarly named fns for binary, unsigned, octal, and hexadec printing)*/

/* Function to handle non-printable characters */
int print_non_printable(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Function to print memory addresses */
int print_memory_address(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Functions for handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Utility function to print string in reverse */
int print_reversed_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Utility function to print a string in ROT13 */
int print_rot13_string(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* Utility function to handle width and padding */
int handle_write_char(char c, char buffer[],
        int flags, int width, int precision, int size);
/*...(similarity named utility fns for writing nums, ptrs, and unsigned val)*/

/** UTILITY FUNCTIONS **/
/*...(defn for is_printable_char, append_hex_code, is_digit_char, etc.)*/

#endif

