#include <stdio.h>
#include "exponentiation.h"

void test_montgomery_ladder() {
    u29 base[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584, 0};
    u29 exponent[WORDS] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u29 mod[WORDS] = {
        535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0
    };
    u29 mu[WORDS] = {
        450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35
    };
    u29 result[WORDS] = {0};

    montgomery_ladder_exponentiation(base, exponent, mod, mu, result);
    print_array("Montgomery Ladder Result", result, WORDS);
}

void test_left_to_right_exponentiation() {
    u29 base[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584, 0};
    u29 exponent[WORDS] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u29 mod[WORDS] = {
        535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0
    };
    u29 mu[WORDS] = {
        450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35
    };
    u29 result[WORDS] = {0};

    left_to_right_binary_exponentiation(base, exponent, mod, mu, result);
    print_array("Left-to-Right Exponentiation Result", result, WORDS);
}

void test_right_to_left_exponentiation() {
    u29 base[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584, 0};
    u29 exponent[WORDS] = {2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u29 mod[WORDS] = {
        535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0
    };
    u29 mu[WORDS] = {
        450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35
    };
    u29 result[WORDS] = {0};

    right_to_left_binary_exponentiation(base, exponent, mod, mu, result);
    print_array("Right-to-Left Exponentiation Result", result, WORDS);
}

int main() {
    test_montgomery_ladder();
    test_left_to_right_exponentiation();
    test_right_to_left_exponentiation();
    return 0;
}
