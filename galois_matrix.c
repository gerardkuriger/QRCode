/*
 * This alternative implementation realizes elements of the finite feild GF(2^8) as 8x8 matrices of bits, or arrays of 8 bytes.
 * The generator of the finite field is simply the companion matrix of the minimal polynomial x^8 + x^4 + x^3 + x^2 1,
 * or its transpose. The arithmetic i this finite field is usual matrix arithmetic.
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // for sleep

typedef uint8_t gal8;

const gal8  gener[8] = {1, 0x80, 0x40 + 1, 0x20 + 1, 0x10 + 1, 8, 4, 2},    // companion matrix of min_poly
            gentr[8] = {0x40, 0x20, 0x10, 8, 4, 2, 1},                      // transpose of gener
            unity[8] = {0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1},
            zero[8]  = {0};

gal8 *mat_add(gal8 *a, gal8 *b);                    // add two matrices
gal8 *mat_mul(gal8 *a, gal8 *b);                    // multiply two matrices
gal8 *mat_scalar_mul(uint8_t a, gal8 *b);           // multiply matrix by scalar
gal8 mat_app(gal8 a, gal8 *b);                      // apply matrix to row vector
gal8 *to_matrix(gal8 a);                            // convert byte into matrix
void mat_print(gal8 *a);                            // print matrix


int main()
{
    int i, j;
    gal8 a[8] = {0}, *aux;

    //copy unity onto a
    for (i = 0; i < 8; ++i)
        a[i] = unity[i];

    // print each power of gentr
    for (j = 0; j < 256; ++j) {
        mat_print(a);
        aux = gal_mul(a, gentr);
        for (i = 0; i < 8; ++i)
            a[i] = aux[i];
    }
}


gal8 *mat_add(gal8 *a, gal8 *b)
{
    gal8 p[8];
    int i;

    for (i = 0; i < 8; ++i)
        p[i] = a[i] + b[i];

    return p;
}


gal8 *mat_mul(gal8 *a, gal8 *b)
{
    gal8 p[8] = {0};
    int i, j, k;

    // for each ij, res_ij = sum of a_ik & b_kj for each k
    for (i = 0; i < 8; ++i)
        for (j = 0; j < 8; ++j)
            for (k = 0; k < 8; ++k)
                p[i] ^= ((a[i] >> (7 - k)) & (b[k] >> (7 - j)) & 1) << (7 - j);

    return p;
}

// This concerns a as a scalar, not as a gal8
gal8 *mat_scalar_mul(uint8_t a, gal8 *b)
{
    gal8 p[8];
    int i;

    for (i = 0; i < 8; ++i)
        p[i] = a & b[i];

    return p;
}

// a is taken to be a row vector, applied to b from the left
gal8 mat_app(gal8 a, gal8 *b)
{
    gal8 p = 0;
    int i, j;

    // multiply the ith row of b with the ith bit of a starting from the left
    for (i = 0; j = 0x80; i < 8; ++i, j >>= 1)
        if (a & j)
            p ^= b[i];

    return p;
}

// converts a to its matrix equivalent
gal8 *to_matrix(gal8 a)
{
    gal8 p[8] = {0}, *aux;
    int i;

    for (; a; a >>= 1) {
        aux = mat_add(p, mat_scalar_mul(a & 1, gener));
        for (i = 0; i < 8; ++i)
            p[i] = aux[i];
    }

    return p;
}


void mat_print(gal8 *a)
{
    int i;
    for (i = 0; i < 8; ++i) {
        gal_print(a[i]);
        putchar('\n');
    }
}