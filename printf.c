#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * printf.c - Implementation of basic printf functionality
 * This file contains an implementation of the printf() function with
 * support for basic formatting specifiers (%d, %i, %c, %s).
 * The functions in this file mimic some of the core functionality of
 * the standard printf() function from the C library. It implements
 * variable argument parsing and formatting/output of common integer
 * and string types.
 * Limitations:
 * Only supports %d, %i, %c, %s specifiers
 * No padding, alignment or field width handling
 * No support for floating point or other complex types
 * Buffer size for output is fixed
 * Dependencies:
 * stdio.h (for printf prototype and FILE type)
 */
int _printc(char c) {
write(1, &c, 1);
return (1);
}
int _prints(char *s) {
int i, len = 0;
for (i = 0; s[i] != '\0'; i++) {
len += write(1, &s[i], 1);
}
len += write(1, "\n", 1);
return (len);
}
int _printf(const char *format, ...) {
int i, len = 0;
va_list args;
char *s;
char c;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++) {
if (format[i] == '%') {
i++;
if (format[i] == 'c') {
c = va_arg(args, int);
len += _printc(c);
}
else if (format[i] == 's') {
s = va_arg(args, char*);
len += _prints(s);
}
}
else {
len += write(1, &format[i], 1);
}
}
va_end(args);
return (len);
}
