#include "../../include/ft_printf.h"

void recursive_putnbr_base_fd(unsigned long long nbr, char *base, int fd)
{
    int base_len = 16;  // Estamos usando la base hexadecimal

    if (nbr >= (unsigned long long)base_len)
    {
        recursive_putnbr_base_fd(nbr / base_len, base, fd);
    }
    ft_putchar_fd(base[nbr % base_len], fd);
}

void ft_putpointer_fd(void *ptr, int fd)
{
    unsigned long long ptr_value = (unsigned long long)ptr;

    ft_putstr_fd("0x", fd);
    recursive_putnbr_base_fd(ptr_value, "0123456789abcdef", fd);
}