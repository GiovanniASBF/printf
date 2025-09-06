# ft_printf
## A reimplementation of the printf function in C language
A project to deepen my knowledge about variadic functions, strings manipulation and memory management in C.

## Overview
This project is an implementation of the iconic printf function of the standard C library (<stdio.h>), developed as part of 42SP curriculum. The main goal was to implement the handling of a variable number of arguments and the strings formatting logic based in format specifiers.

## Key learnings
### Variadic Functions
A variadic function is a function that can accept a variable number of arguments. Instead of declare a fixed number of parameters, it's projected to deal with a list of arguments whose size isn't known at compile-time.
To implement a variadic function, there's four main steps:

- va_list: It's basically a pointer used to store the arguments list. Just think of it as a "cursor" that will point to each argument, one at a time.

- va_start(argument_pointer, last_fixed): Initialize the arguments list. The first argument is the list itself. The last one is the last known argument, the part that doesn't vary. It's very important, because it will use its memory address to find where the variable arguments begin in the call stack.

- va_arg(argument_pointer, type): Access the current argument in the list and move the "cursor" to the next. You must tell it what data type is expected. It returns a value and moves the pointer to the next argument position, so you must know what data type you're reading.

- va_end(ap): Clears the arguments list.

## Format Specifiers Implemented
- `%c` – Character  


- `%s` – String  


- `%p` – Pointer address  


- `%d` or `%i` – Signed decimal integer  


- `%u` – Unsigned decimal integer  


- `%x` – Hexadecimal (lowercase)  


- `%X` – Hexadecimal (uppercase)  


- `%%` – A literal percent sign  
