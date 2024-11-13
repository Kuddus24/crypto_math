#ifndef MODULAR_ARITHMETIC_H
#define MODULAR_ARITHMETIC_H

#include <stdint.h>

#define WORDS 10
typedef uint64_t u29;

void normalize(u29* number, int length);
void add_29bit(const u29* a, const u29* b, u29* result, int length);
void sub_29bit(const u29* a, const u29* b, u29* result, int length);
void mult_29bit(const u29* a, const u29* b, u29* result);
void rshift1(u29* num, int length);
int geq(const u29* a, const u29* b);
void print_array_brr(const char* label, const u29* arr, int size);
void print_array(const char* label, const u29* arr, int size);

#endif
