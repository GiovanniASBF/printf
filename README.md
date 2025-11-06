# ft_printf

## Overview
**ft_printf** is a reimplementation of the `printf` function from the C standard library (`<stdio.h>`). Developed as part of the 42SP curriculum, this project aims to deepen understanding of variadic functions, string formatting, and low-level memory management in C.

The primary goal was to create a robust function capable of handling a variable number of arguments and formatting them according to specific placeholders, mimicking the behavior of the original function.

## ✨ Features (Format Specifiers)
My implementation supports the following standard format specifiers:

| Specifier | Description | Example Output |
| :---: | :--- | :--- |
| `%c` | Single character | `a` |
| `%s` | String of characters | `Hello, World!` |
| `%p` | Pointer address (in hexadecimal) | `0x7ffeefbff6d8` |
| `%d` / `%i`| Signed decimal integer | `-42` |
| `%u` | Unsigned decimal integer | `42` |
| `%x` | Unsigned hexadecimal (lowercase) | `2a` |
| `%X` | Unsigned hexadecimal (uppercase) | `2A` |
| `%%` | Literal percent sign | `%` |

### Return Value
Just like the standard `printf`, `ft_printf` returns the total **number of characters printed** (excluding the null byte used to end output to strings). If an error occurs, it returns a negative number.

## 🧠 Key Learnings: Variadic Functions

A **variadic function** can accept a flexible number of arguments. Unlike standard functions with a fixed set of parameters, it handles an unknown number of inputs at compile time.

Implementing this required mastering the `<stdarg.h>` macros:

* **`va_list`**: A specialized type that acts as a pointer/cursor to the list of variable arguments.
* **`va_start(va_list ap, last_fixed_arg)`**: Initializes the `va_list` cursor. It needs the last fixed argument to locate the start of the variable arguments in the stack.
* **`va_arg(va_list ap, type)`**: Retrieves the next argument. Crucially, you must specify the expected **type** (e.g., `int`, `char *`) so it knows how many bytes to read and how to interpret them.
* **`va_end(va_list ap)`**: Cleans up the `va_list` cursor after all arguments have been processed.
