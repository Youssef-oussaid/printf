#include <stdarg.h>
#include "main.h"
#include <unistd.h>
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
