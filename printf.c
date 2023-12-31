#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdio.h>
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
int _prints(char *s) {
int len = 0;
while (*s) {
len += write(1, s, 1);
s++;
}
return len;
}
int _printf(const char *format, ...)
{
int len = 0;
va_list args;
va_start(args, format);
while (*format) {
if (*format == '%') {
format++;
switch (*format) {
case 'd':
case 'i': {
int num = va_arg(args, int);
char buffer[32];
int count;
count = snprintf(buffer, sizeof(buffer), "%d", num);
len += write(1, buffer, count);
break;
}
default:
len += write(1, format, 1);
break;
}
}
else {
len += write(1, format, 1);
}
format++;
}
va_end(args);
return (len);
}
int _printc(char c) {
return write(1, &c, 1);
}
