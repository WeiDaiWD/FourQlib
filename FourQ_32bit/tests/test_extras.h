/***********************************************************************************
* FourQlib: a high-performance crypto library based on the elliptic curve FourQ
*
*    Copyright (c) Microsoft Corporation. All rights reserved.
*
* Abstract: utility header file for tests
************************************************************************************/  

#ifndef __TEST_EXTRAS_H__
#define __TEST_EXTRAS_H__


// For C++
#ifdef __cplusplus
extern "C" {
#endif


#if TARGET == TARGET_ARM
    #define print_unit printf("nsec");
#else
    #define print_unit printf("cycles");
#endif

    
// Access system counter for benchmarking
int64_t cpu_nseconds(void);

// Comparing uint32_t digits of two field elements, a=b? : (0) equal, (1) unequal
int vcompare32(uint32_t* a, uint32_t* b);

// Comparing uint32_t digits of two quadratic extension field elements, ai=bi? : (0) equal, (1) unequal
int v2compare32(uint32_t* a, uint32_t* b);

// Comparing uint64_t digits of two field elements, a=b? : (0) equal, (1) unequal
int fpcompare64(uint64_t* a, uint64_t* b);

// Comparing uint64_t digits of two quadratic extension field elements, ai=bi? : (0) equal, (1) unequal
int fp2compare64(uint64_t* a, uint64_t* b);

// Generating a pseudo-random scalar value in [0, 2^256-1] 
void random_scalar_test(uint64_t* a);

// Generating a vectorized pseudo-random GF(p) element in [0, 2^127-1] 
void vrandom1271_test(velm_t a);

// Generating a pseudo-random GF(p^2) element a+b*i, where a,b in [0, 2^127-1] 
void fp2random1271_test(f2elm_t a);

// Generating a vectorized pseudo-random GF(p^2) element a+b*i, where a,b in [0, 2^127-1] 
void v2random1271_test(v2elm_t a);

// Verification of the mLSB-set's recoding algorithm used in fixed-base scalar multiplication 
bool verify_mLSB_recoding(uint64_t* scalar, int* digits);


#ifdef __cplusplus
}
#endif


#endif