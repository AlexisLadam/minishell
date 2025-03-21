/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>

int my_print_unsign(char *format, va_list list, int *i, int *comptchar);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_putcharm(char c, int *comptchar);
int my_putstrm(char const *str, int *comptchar);
int my_compute_power_rec(int nb, int p);
int my_put_nbrm(int nb, int *comptchar);
int f_no_cond(char *format, va_list list, int *i, int *comptchar);
int f_6_chfr(char *format, va_list list, int *i, int *comptchar);
int calcul_nombre(char *format, va_list list, int *i, int *comptchar);
int flag_f(char *format, va_list list, int *i, int *comptchar);
int affichage_mini_printf(char *format, va_list list, int *i, int *comptchar);
int affichage_flag_f(char *format, va_list list, int *i, int *comptchar);
int appelall(char *format, va_list list, int *i, int *comptchar);
int my_printf(char *format, ...);
int my_uns_oct(unsigned long decimalnum, int *comptchar);
int my_pointer(unsigned long decimal, int *comptchar);
int my_uns_hex(unsigned long decimal, int *comptchar);
int my_maj_hex(unsigned long decimal, int *comptchar);
int rem_to_char(char rem, char *str, int i, int *comptchar);
int rem_to_char_min(char rem, char *str, int i, int *comptchar);
int my_uns_nbr(unsigned long nb, int *comptchar);
int moins_en_plus(int l);
void my_print_scientifique(char *format, va_list list, int *i, int *comptchar);
void dec_to_sci(double decimal, int majuscule, int *comptchar);
void espacesupp(int majuscule, int virg, int *comptchar);
void test_flag(char *format, va_list list, int *i, int *comptchar);
void test_flag_plus(char *format, va_list list, int *i, int *comptchar);
#endif
