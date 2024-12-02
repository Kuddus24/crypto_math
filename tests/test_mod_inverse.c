void test_mod_inverse() {
    printf("Running mod_inverse Test...\n");


    u29 mod[WORDS] = {535425013, 174332635, 444665496, 192778653, 388389189, 518147849, 304619691, 363717891, 15281728, 0};
    u29 mu[WORDS] = {450887704, 490307913, 387807083, 403879883, 291135210, 307268612, 110539282, 24605042, 70628772, 35};
    u29 x[WORDS] = {239807541, 463493311, 126630807, 163696075, 216258560, 57519157,0,0,0,0};
    u29 result[WORDS] = {0};

    u29 result[WORDS] = {0};

    mod_inverse(x, mod, mu, result);

    print_array_brr("Modular Inverse", result, WORDS);
}
