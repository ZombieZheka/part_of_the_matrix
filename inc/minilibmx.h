#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

double mx_pow(double, unsigned int);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
char *mx_itoa(int number);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printchar(char c);
int mx_strncmp(const char *s1, const char *s2, int n);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char**);
bool mx_check(int, char*);
void mx_printerr(const char*);
void mx_print_error(const char*, const char*);
void mx_check_operands(char**, char*, char*, char*, char*);

#endif
