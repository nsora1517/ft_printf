#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    // %c
    ret1 = ft_printf("ft: %c\n", 'A');
    ret2 = printf("og: %c\n", 'A');
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %s
    ret1 = ft_printf("ft: %s\n", "hello");
    ret2 = printf("og: %s\n", "hello");
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %s NULL
    ret1 = ft_printf("ft: %s\n", NULL);
    printf("ft_ret:%d\n\n", ret1);

    // %p
    int x = 42;
    ret1 = ft_printf("ft: %p\n", &x);
    ret2 = printf("og: %p\n", &x);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %p NULL
    ret1 = ft_printf("ft: %p\n", NULL);
    ret2 = printf("og: %p\n", NULL);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %d
    ret1 = ft_printf("ft: %d\n", 42);
    ret2 = printf("og: %d\n", 42);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %d\n", -42);
    ret2 = printf("og: %d\n", -42);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %d\n", 0);
    ret2 = printf("og: %d\n", 0);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %d\n", (int)-2147483648);
    ret2 = printf("og: %d\n", (int)-2147483648);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %i
    ret1 = ft_printf("ft: %i\n", 123);
    ret2 = printf("og: %i\n", 123);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %u
    ret1 = ft_printf("ft: %u\n", 42u);
    ret2 = printf("og: %u\n", 42u);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %u\n", 0u);
    ret2 = printf("og: %u\n", 0u);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %u\n", 4294967295u);
    ret2 = printf("og: %u\n", 4294967295u);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %x
    ret1 = ft_printf("ft: %x\n", 255);
    ret2 = printf("og: %x\n", 255);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    ret1 = ft_printf("ft: %x\n", 0);
    ret2 = printf("og: %x\n", 0);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %X
    ret1 = ft_printf("ft: %X\n", 255);
    ret2 = printf("og: %X\n", 255);
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    // %%
    ret1 = ft_printf("ft: 100%%\n");
    ret2 = printf("og: 100%%\n");
    printf("ft_ret:%d og_ret:%d\n\n", ret1, ret2);

    return 0;
}
