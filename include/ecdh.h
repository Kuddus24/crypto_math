#ifndef ECDH_H
#define ECDH_H

#include <stdint.h>
#include "crypto_math.h"

// Constants for the elliptic curve
#define WORDS 10              // Number of 29-bit words
#define BASE (1UL << 29)      // 2^29, representing the base
#define BASE29_MASK 0x1FFFFFFF // Mask for 29-bit values

// Type definitions
typedef uint64_t u29; // 64-bit unsigned integer, storing only 29-bit values

// Structure to represent an elliptic curve point
typedef struct {
    u29 x[WORDS];       // x-coordinate
    u29 y[WORDS];       // y-coordinate
    int is_infinity;    // 1 if the point is at infinity, 0 otherwise
} ECPoint;

// Function Declarations

/**
 * @param mod The modulus of the field.
 * @param mu The Barrett constant.
 */
void mod_inverse(u29* x, u29* p, u29* mu, u29* result);

/**
 * Elliptic curve point addition.
 * @param P First elliptic curve point.
 * @param Q Second elliptic curve point.
 * @param result Output parameter for the resulting point after addition.
 * @param mod The modulus of the field.
 * @param mu The Barrett constant.
 */
void ecc_add(ECPoint* P, ECPoint* Q, ECPoint* result, u29* mod, u29* mu);

/**
 * Elliptic curve point doubling.
 * @param P The elliptic curve point to be doubled.
 * @param result Output parameter for the resulting point after doubling.
 * @param mod The modulus of the field.
 * @param mu The Barrett constant.
 */
void ecc_double(ECPoint* P, ECPoint* result, u29* mod, u29* mu);

/**
 * Elliptic curve scalar multiplication using the left-to-right binary method.
 * @param scalar The scalar multiplier.
 * @param P The elliptic curve point to be multiplied.
 * @param result Output parameter for the resulting point after multiplication.
 * @param mod The modulus of the field.
 * @param mu The Barrett constant.
 */
void ecc_scalar_mult_l2r(u29* scalar, ECPoint* P, ECPoint* result, u29* mod, u29* mu);

/**
 * Elliptic curve scalar multiplication using the right-to-left binary method.
 * @param scalar The scalar multiplier.
 * @param P The elliptic curve point to be multiplied.
 * @param result Output parameter for the resulting point after multiplication.
 * @param mod The modulus of the field.
 * @param mu The Barrett constant.
 */
void ecc_scalar_mult_r2l(u29* scalar, ECPoint* P, ECPoint* result, u29* mod, u29* mu);

#endif // ECDH_H
