#include "modular_arithmetic.h"
#include <string.h>

#define WORDS 10               // Number of 29-bit words for 256-bit integer representation
#define BASE (1UL << 29)       // 2^29, representing the base
typedef uint64_t u29;          // Use 64-bit unsigned integers, storing only 29-bit values
#define BASE29_MASK 0x1FFFFFFF // Mask for 29-bit values



// Normalize to handle carries in a 29-bit base system
void normalize(u29* number, int length) {
    uint64_t carry = 0;
    for (int i = 0; i < length; i++) {
        uint64_t value = (uint64_t)number[i] + carry;
        number[i] = value % BASE; // Retain only 29 bits
        carry = value / BASE;     // Propagate carry
    }
}



// Helper function to perform right shift by 1 bit
void rshift1(u29* num, int length) {
    for (int i = 0; i < length - 1; i++) {
        num[i] = (num[i] >> 1) | ((num[i + 1] & 1) << 28);
    }
    num[length - 1] >>= 1;
}



// Modular addition
void add_29bit(const u29* a, const u29* b, u29* result, int length) {
    uint64_t carry = 0;
    for (int i = 0; i < length; i++) {
        uint64_t sum = (uint64_t)a[i] + b[i] + carry;
        result[i] = sum % BASE;
        carry = sum / BASE;
    }
    normalize(result, length);
}



//Modular Substruction
void sub_29bit(const u29* a, const u29* b, u29* result, int length) {
    uint64_t carry = 1;  // Start with carry = 1 for the 2's complement of b

    for (int i = 0; i < length; i++) {
        uint64_t diff = (uint64_t)a[i] + (~b[i] & BASE29_MASK) + carry;
        result[i] = diff % BASE;   // Keep only the lowest 29 bits
        carry = diff / BASE;       // Set carry for the next word
    }
    
    // Check if result is negative (borrow occurred)
    if (carry == 0) { // Borrow indicates a negative result
        // Add the modulus to ensure the result is positive
        add_29bit(result, mod, result, length);
    }
 }




// Schoolbook multiplication
void mult_29bit(const u29* a, const u29* b, u29* result) {
    memset(result, 0, 2 * WORDS * sizeof(u29)); // Initialize result to zero
    for (int i = 0; i < WORDS; i++) {
        uint64_t carry = 0;
        for (int j = 0; j < WORDS; j++) {
            uint64_t product = (uint64_t)a[i] * b[j] + result[i + j] + carry;
            result[i + j] = product % BASE;
            carry = product / BASE;
        }
        result[i + WORDS] += carry;
    }
    normalize(result, 2 * WORDS);
}



// Function to check if a >= b for multi-word numbers
int geq(const u29* a, const u29* b) {
    for (int i = WORDS - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 1; // a == b
}



// Modular multiplication with Barrett reduction
void modular_multiply(u29* a, u29* b, u29* result, u29* mod, u29* mu) {
    u29 temp[2 * WORDS] = {0}; // Temporary variable to hold multiplication result
    mult_29bit(a, b, temp);    
    barrett_reduction(temp, mod, mu, result); 
}


// Print function for debugging
void print_array(const char* label, const u29* arr, int size) {
    printf("%s: ", label);
    for (int i = size - 1; i >= 0; i--) {
        printf("%lu ", (unsigned long)arr[i]);
    }
    printf("\n");
}

// Print function for debugging for barrett
void print_array_brr(const char* label, const u29* arr, int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; i++) {
        printf("%lu ", (unsigned long)arr[i]);
    }
    printf("\n");
}


