#include <stdio.h>
#include "include/ft_printf.h"  // Asegúrate de que esta ruta sea correcta

int main()
{
    char c = 'A';
    char *s = "Hola";
    int i = -42;
    unsigned int u = 42;
    void *p = &i;
    int d = 42;

    printf("=== Pruebas con printf ===\n");

    printf("Prueba con %%c: %c\n", c);
    printf("Prueba con %%s: %s\n", s);
    printf("Prueba con %%i: %i\n", i);
    printf("Prueba con %%u: %u\n", u);
    printf("Prueba con %%p: %p\n", p);
    printf("Prueba con %%X: %X\n", d);
    printf("Prueba con %%x: %x\n", d);
    printf("Prueba con %%d: %d\n", d);
    printf("Prueba con %%%%: %%\n");

    printf("\n=== Pruebas con ft_printf ===\n");

    ft_printf("Prueba con %%c: %c\n", c);
    ft_printf("Prueba con %%s: %s\n", s);
    ft_printf("Prueba con %%i: %i\n", i);
    ft_printf("Prueba con %%u: %u\n", u);
    ft_printf("Prueba con %%p: %p\n", p);
    ft_printf("Prueba con %%X: %X\n", d);
    ft_printf("Prueba con %%x: %x\n", d);
    ft_printf("Prueba con %%d: %d\n", d);
    ft_printf("Prueba con %%%%: %%\n");

    return 0;
}