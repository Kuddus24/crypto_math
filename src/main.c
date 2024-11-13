#include <stdio.h>
#include "modular_arithmetic.h"
#include "barrett_reduction.h"
#include "exponentiation.h"

int main() {
    u29 a[WORDS] = {367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584};
    u29 b[WORDS] =  {183537, 155167226, 196914793, 415632788, 305808344, 265080239, 428181196, 33008820, 108065792};
    u29 x[20] = {262796738, 291041765, 227197060, 268576731, 88602942, 92985658, 26177716, 76424348, 37458289, 134214318, 
                263835569, 386210311, 160323224, 315620857, 161349371, 305704035, 313886971, 43504742,0,0};
    u29 mod[WORDS] = {535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728,0};
    u29 mu[WORDS] = {450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};//MU=2^(522

    u29 exponent[WORDS]  ={2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    u29 base[WORDS] ={367074, 310334452, 393829586, 294394664, 74745777, 530160479, 319491480, 66017641, 216131584,0};
    u29 result[WORDS] = {0};
    right_to_left_binary_exponentiation(base,exponent,mod,mu,result);
    print_array_brr("Right to Left exponentiation result : ",result,WORDS);

    left_to_right_binary_exponentiation(base,exponent,mod,mu,result);
    print_array_brr(" Left to Right exponentiation result : ",result,WORDS);

    montgomery_ladder_exponentiation(base, exponent, mod, mu, result);
    print_array_brr("Montgomery ladder exponentiation result: ", result, WORDS);

    // Perform Barrett reduction
    barrett_reduction(x, mod, mu, result);
    print_array_brr("Reduced Result", result, WORDS);
    
    modular_multiply(a,b,result,mod,mu);
    print_array_brr("Modular Multiplication Result: ",result, WORDS);
    Initialize base g and exponent k
   
    return 0;
}
