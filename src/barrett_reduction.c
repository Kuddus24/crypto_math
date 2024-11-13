
//barret reduction
void barrett_reduction(u29* a, u29* mod, u29* mu, u29* result) {
    u29 q1[WORDS] = {0};
    u29 q2[2 * WORDS] = {0};
    u29 q3[WORDS] = {0};
    u29 temp[2 * WORDS] = {0};
    u29 rem[WORDS + 1] = {0};

    // Step 1: Initialize q1 with a[8] to a[17]
    memcpy(q1, a + 8, (WORDS) * sizeof(u29));

    // Step 2: q2 = q1 * mu
    mult_29bit(q1, mu, q2);

    // Step 3: Populate q3 with q2[10] to q2[19]
    memcpy(q3, q2 + WORDS, WORDS * sizeof(u29));

    // Step 4: temp = q3 * mod
    mult_29bit(q3, mod, temp);

    // Step 5: rem = a - temp
    sub_29bit(a, temp, rem, WORDS + 1);

    // Step 6: Adjust remainder to ensure rem < mod
    while (geq(rem, mod)) {
        sub_29bit(rem, mod, rem, WORDS + 1);
    }

    // Store result in output parameter
    memcpy(result, rem, WORDS * sizeof(u29));
}
