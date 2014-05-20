/*** This is a portable random number generator whose origins are
 *** unknown.  As far as can be told, this is public domain software.
 ***/

/*** portable random number generator */

/*** Note that every variable used here must have at least 31 bits
 *** of precision, exclusive of sign.  Long integers should be enough.
 *** The generator is the congruential:  i = 7**5 * i mod (2^31-1).
 ***/

#include "random.h"

static long saved_seed;
static long saved_seed2;


/*** set_randomi - initialize constants and seed */

void set_randomi(long seed)
{
	saved_seed = seed;
	saved_seed2 = (saved_seed - 1000) % MODULUS;
}


/*** randomi - generate a random integer in the interval [a,b] (b >= a >= 0) */

long randomi(long a, long b)
{
	register long hi, lo;

	hi = MULTIPLIER * (saved_seed >> 16);
	lo = MULTIPLIER * (saved_seed & 0xffff);
	hi += (lo>>16);
	lo &= 0xffff;
	lo += (hi>>15);
	hi &= 0x7fff;
	lo -= MODULUS;
	if((saved_seed = (hi<<16) + lo) < 0) {
		saved_seed += MODULUS;
	}

	if(b <= a) {
		return b;
	}
	
	return a + saved_seed % (b - a + 1);
}

long randomi2(long a, long b)
{
	register long hi, lo;

	hi = MULTIPLIER * (saved_seed2 >> 16);
	lo = MULTIPLIER * (saved_seed2 & 0xffff);
	hi += (lo>>16);
	lo &= 0xffff;
	lo += (hi>>15);
	hi &= 0x7fff;
	lo -= MODULUS;
	if((saved_seed2 = (hi<<16) + lo) < 0) {
		saved_seed2 += MODULUS;
	}

	if(b <= a) {
		return b;
	}
	
	return a + saved_seed2 % (b - a + 1);
}
