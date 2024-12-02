# Montgomery Exponentiation with Barrett Reduction

This project implements various modular arithmetic operations, Barrett reduction, and Montgomery ladder-based modular exponentiation. The implementation is optimized for cryptographic computations, focusing on 256-bit integers represented using a 29-bit word system.

## Project Context

This project was developed to perform modular arithmetic and exponentiation with the following **256-bit prime number**:

**p = 105470615072424007464777057006017113535036866827082468263120632948849084329973**

With this prime, I implemented efficient modular arithmetic, reduction, and exponentiation techniques tailored for large integers in cryptographic applications.
### Features

# BigNumHexParser

A C program to parse 64-character hexadecimal strings into big integer arrays. The program is designed to handle cryptographic operations where numbers are represented in base 2^29.

## Features
- Parse a 64-character hexadecimal string into a big integer array of 29-bit words.
- Handles invalid hexadecimal characters gracefully.
- Includes test cases for validation.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/<username>/BigNumHexParser.git
   cd BigNumHexParser

## Modular Arithmetic

- **Addition**: Handles carry normalization within a 29-bit word system.
- **Subtraction**: Implements efficient modular subtraction using two's complement.
- **Multiplication**: Implements a schoolbook multiplication algorithm optimized for the 29-bit base system.
- **Right Shift**: Performs bitwise right shifts for large integers.
- **Comparison**: Checks if one large number is greater than or equal to another.

## Barrett Reduction

- **Efficient modular reduction** using the precomputed constant `μ = 2^522`.
- Reduces large numbers modulo the prime `p` without requiring division operations.

## Modular Exponentiation

- **Montgomery Ladder Exponentiation**: Secure against side-channel attacks.
- **Left-to-Right Binary Exponentiation**: Computes `g^k mod p` from the most significant bit (MSB) to the least significant bit (LSB).
- **Right-to-Left Binary Exponentiation**: Computes `g^k mod p` from the least significant bit (LSB) to the most significant bit (MSB).
  ## Build Instructions

### Prerequisites
- **GCC Compiler** (or any C compiler)
- **Make** (optional, for using the provided Makefile)

### Steps

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Kuddus24/crypto_math.git
   cd crypto_math


  ## Build Instructions
   # Clone the repository:
   git clone https://github.com/Kuddus24/crypto_math.git

  ## Build the Project
    ```bash
          make
 # **Run the Main Program**
      ./main
      
  **Run Tests**
 
  ```bash

## Modular Arithmetic Tests:
   gcc -o test_modular tests/test_modular.c src/modular_arithmetic.c -Iinclude
   ./test_modular 
 
## Barrett Reduction Test:
  gcc -o test_barrett tests/test_barrett.c src/barrett_reduction.c src/modular_arithmetic.c -Iinclude
  ./test_barrett

## Exponentiation Tests:
 gcc -o test_exponentiation tests/test_exponentiation.c src/exponentiation.c src/barrett_reduction.c src/modular_arithmetic.c -Iinclude
 ./test_exponentiation 



