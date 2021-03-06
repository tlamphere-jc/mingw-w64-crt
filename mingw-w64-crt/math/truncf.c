/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>
#include <math.h>

float
truncf (float _x)
{
  float retval = 0.0F;
  unsigned short saved_cw;
  unsigned short tmp_cw;
  __asm__ __volatile__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
  tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
	    | FE_TOWARDZERO;
  __asm__ __volatile__ ("fldcw %0;" : : "m" (tmp_cw));
  __asm__ __volatile__ ("frndint;" : "=t" (retval)  : "0" (_x)); /* round towards zero */
  __asm__ __volatile__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
  return retval;
}
