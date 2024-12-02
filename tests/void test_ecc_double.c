void test_ecc_double() {
    printf("Running ecc_double Test...\n");

    ECPoint P = {
        .x = {106941203, 466067982, 438550057, 390471449, 83772637, 320472647, 147247182, 309378531, 14677865, 0},
        .y = {415531087, 405911950, 252905948, 246890892, 45920082, 349355649, 136411145, 205479438, 9595215, 0},
        .is_infinity = 0
    };
    u29 mod[WORDS] = {535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0};
    u29 mu[WORDS] = {450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};
    ECPoint result_double = {0};

  
    // Perform doubling
    ecc_double(&P, &result_double, mod, mu);
    printf("\nDoubling Result:\n");
    print_array_brr("X", result_double.x,WORDS);
    print_array_brr("Y", result_double.y,WORDS);
}
