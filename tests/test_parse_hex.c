#include <stdio.h>
#include <string.h>
#include "../src/parse_hex.c" // Include the main file for testing

void test_parse_to_int() {
    char hex[65] = "e92e40ad6f281c8a082afdc49e1372659455bec8ceea043a614c835b7fe9eff5";
    u29 bignum[N] = {0};

    parse_to_int(hex, bignum);

    printf("Test: Parsing predefined hexadecimal string:\n%s\n", hex);
    printf("Converted big integer array:\n");
    for (int i = 0; i < N; i++) {
        printf("bignum[%d] = %llu\n", i, bignum[i]);
    }
    printf("Test Completed.\n");
}

int main() {
    test_parse_to_int();
    return 0;
}
