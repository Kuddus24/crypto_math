#ifndef MONTGOMERY_LADDER_H
#define MONTGOMERY_LADDER_H

#include "modular_arithmetic.h"
#include "barrett_reduction.h"

void montgomery_ladder_exponentiation(u29* base, u29* exponent, u29* mod, u29* mu, u29* result);
void left_to_right_binary_exponentiation(u29* base, u29* exponent, u29* mod, u29* mu, u29* result);
void right_to_left_binary_exponentiation(u29* base, u29* exponent, u29* mod, u29* mu, u29* result);

#endif
