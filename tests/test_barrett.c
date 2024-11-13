#include <stdio.h>
#include <stdint.h>
#include "barrett_reduction.h"

void test_barrett_reduction() {
    u29 a[20] = {262796738, 291041765, 227197060, 268576731, 88602942, 92985658, 26177716, 76424348, 37458289, 134214318, 
               263835569, 386210311, 160323224, 315620857, 161349371, 305704035, 313886971, 43504742,0,0};
    u29 mod[WORDS] = {
        535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0};
    u29 mu[WORDS] = {
        450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};
    u29 result[WORDS] = {0};

    barrett_reduction(a, mod, mu, result);
    print_array_brr("Barrett Reduction Result", result, WORDS);
}

int main() {
    test_barrett_reduction();
    return 0;
}
