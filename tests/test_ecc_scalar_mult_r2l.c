void test_ecc_scalar_mult_r2l() {
    printf("Running ecc_scalar_mult_r2l Test...\n");

    ECPoint G = {
        .x = {511206874, 254855740, 285194860, 443465366, 268068044, 451848614, 325285346, 118243884, 13861873,0},
        .y = {473912554, 460180803, 198869900, 64737929, 437536564, 372033891, 274885473, 29463607, 4333742,0},
        .is_infinity = 0
    };
    u29 mod[WORDS] = {535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0};
    u29 mu[WORDS] = {450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};
    ECPoint result_scalar_mult_r2l = {0};

    // Perform scalar multiplication (right-to-left)
    ecc_scalar_mult_r2l(scalar, &G, &result_scalar_mult_r2l, mod, mu);
    printf("\nScalar Multiplication (R2L) Result:\n");
    print_array_brr("X", result_scalar_mult_r2l.x, WORDS);
    print_array_brr("Y", result_scalar_mult_r2l.y, WORDS);
}
