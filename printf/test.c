#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret_val;

    printf("--- Testing basic strings and integers ---\n");
    ft_printf("Hello, world!\n");
    printf("Expected: Hello, world!\n\n");

    ret_val = ft_printf("The number is %d\n", 42);
    printf("Expected: The number is 42 (ret value: %d)\n\n", ret_val);

    ret_val = printf("The number is %d\n", 42);
    printf("Expected: The number is 42 (ret value: %d)\n\n", ret_val);

    printf("--- Testing multiple specifiers ---\n");
    ret_val = ft_printf("Char: %c, String: %s, Int: %i\n", 'A', "test string", -10);
    printf("Expected: Char: A, String: test string, Int: -10 (ret value: %d)\n\n", ret_val);

    ret_val = printf("Char: %c, String: %s, Int: %i\n", 'A', "test string", -10);
    printf("Expected: Char: A, String: test string, Int: -10 (ret value: %d)\n\n", ret_val);

    printf("--- Testing edge cases and special formats ---\n");
    ret_val = ft_printf("Empty string: %s\n", "");
    printf("Expected: Empty string:  (ret value: %d)\n\n", ret_val);

    ret_val = ft_printf("NULL pointer: %s\n", (char *)NULL);
    printf("Expected: NULL pointer: (null) or similar (ret value: %d)\n\n", ret_val);

    ret_val = ft_printf("Hex: %x, Pointer: %p\n", 255, &ret_val);
    printf("Expected: Hex: ff, Pointer: <some address> (ret value: %d)\n\n", ret_val);

    return 0;
}