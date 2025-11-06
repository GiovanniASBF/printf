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
