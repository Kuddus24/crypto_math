#include <stdio.h>
#include <stdint.h>
#include "modular_arithmetic.h"

u29 mod[WORDS] = {535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728,0};
u29 mu[WORDS] = {450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};//MU=2^(522)
void test_addition() {
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 b[WORDS] =  {183537, 155167226, 196914793, 415632788, 305808344, 265080239, 428181196, 33008820, 108065792};
    u29 result[WORDS] = {0};

    add_29bit(a, b, result, WORDS);
    print_array("Addition Result", result, WORDS);
}

void test_subtraction() {
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 b[WORDS] =  {183537, 155167226, 196914793, 415632788, 305808344, 265080239, 428181196, 33008820, 108065792};
    u29 result[WORDS] = {0};

    sub_29bit(a, b, result, WORDS);
    print_array("Subtraction Result", result, WORDS);
}

void test_right_shift() {
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 result[WORDS] = {0};

    memcpy(result, a, sizeof(a));
    rshift1(result, WORDS);
    print_array("Right Shift Result", result, WORDS);
}

void test_geq() {
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 b[WORDS] =  {183537, 155167226, 196914793, 415632788, 305808344, 265080239, 428181196, 33008820, 108065792};
    printf("Comparison Result (a >= b): %d\n", geq(a, b));
}

void test_modular_multiply() {
   
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 b[WORDS] =  {183537, 155167226, 196914793, 415632788, 305808344, 265080239, 428181196, 33008820, 108065792};
    modular_multiply(a,b,result,mod,mu)
    print_array_brr("Modular Multiplication Results: ", result, WORDS);
}

int main() {
    test_addition();
    test_subtraction();
    test_right_shift();
    test_geq();
    test_modular_multiply();
    return 0;
}
