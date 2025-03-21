/*
 * The following is an implementation of the finite field GF(2^8) as bit vectors of length 8, where the nth bit represents the
 * coefficient of the nth power of the generator in each element, and the generator satisfies the minimal polynomial
 * x^8 + x^4 + x^3 + x^2 + 1 in the prime field Z_2, in which addition is equivilent to XOR and multiplication to AND.
 * The elements of GF(2^8) thus represents polynimials of degree < 8 in the generator x. Addition in this field is simply
 * bitwise XOR, but multiplication requires the elimination of powers of x <= 8.
 */


#include <stdio.h>
#include <stdint.h>

typedef uint8_t gal8;                   // Galois Field of 2^8

const gal8 min_poly     = 0b00011011,   // Minimal polynomial x^8 + x^4 + x^3 + x^2 + 1
            generator   = 0b10;         // Generator of Galois Field

gal8 gal_add(gal8 a, gal8 b);           // Add two elements of GF(2^8)
gal8 gal_mul(gal8 a, gal8 b);           // Multiply two elements of GF(2^8)
void gal_print(gal8 a);                  // Print an element of GF(2^8) in binary form
int hamming_norm(int a);                // Number of nonzero bits in a
int hamming_distance(int a, int b);     // Number of different bit between a and b


int main()
{
    int i = 0, c = 0;
    gal8 a = 1;
    while (i++ < 256) {
        gal_print(a);
        // printf("%d", hamming_distance(a, gal_mul(a, generator)));
        a = gal_mul(a, generator);
        if (c++ < 7) {
            putchar(' ');
        } else {
            putchar('\n');
            c = 0;
        }
    }
    if (c)
        putchar('\n');
}


gal8 gal_add(gal8 a, gal8 b)
{
    return a ^ b;
}


gal8 gal_mul(gal8 a, gal8 b)
{
    gal8 p = 0;
    for (; b; b >>= 1) {
        if (b & 1)
            p ^= a;
        if (a & 0x80)
            a = (a << 1) ^ min_poly;
        else
            a <<= 1;
    }
    return p;
}


void gal_print(gal8 a)
{
    int i = 0;
    while (i--)
        putchar((a >> 1 & 1) + '0');
}


int hamming_norm(int a)
{
    int p = 0;
    while (a){
        if (a & 1) ++p;
        a >>= 1;
    }
    return p;
}


int hamming_distance(int a, int b)
{
    return hamming_norm(a ^ b);
}